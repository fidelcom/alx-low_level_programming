#include "main.h"

void check_e(unsigned char *ptr);
void output_magic(unsigned char *ptr);
void output_class(unsigned char *ptr);
void output_data(unsigned char *ptr);
void output_version(unsigned char *ptr);
void output_abi(unsigned char *e_ident);
void output_osabi(unsigned char *e_ident);
void output_type(unsigned int e_type, unsigned char *e_ident);
void output_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_e(int desc);

/**
 * check_e - Checks if a file is an ELF file.
 * @ptr: A pointer to an array containing the ELF magic numbers.
 *
 */
void check_e(unsigned char *ptr)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ptr[i] != 127 &&
		    ptr[i] != 'E' &&
		    ptr[i] != 'L' &&
		    ptr[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * output_magic - Prints the magic numbers of an ELF header.
 * @ptr: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void output_magic(unsigned char *ptr)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ptr[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * output_class - Prints the class of an ELF header.
 * @ptr: A pointer to an array containing the ELF class.
 */
void output_class(unsigned char *ptr)
{
	printf("  Class:                             ");

	switch (ptr[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", ptr[EI_CLASS]);
	}
}

/**
 * output_data - Prints the data of an ELF header.
 * @ptr: A pointer to an array containing the ELF class.
 */
void output_data(unsigned char *ptr)
{
	printf("  Data:                              ");

	switch (ptr[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", ptr[EI_CLASS]);
	}
}

/**
 * output_version - Prints the version of an ELF header.
 * @ptr: A pointer to an array containing the ELF version.
 */
void output_version(unsigned char *ptr)
{
	printf("  Version:                           %d",
	       ptr[EI_VERSION]);

	switch (ptr[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * output_osabi - Prints the OS/ABI of an ELF header.
 * @ptr: A pointer to an array containing the ELF version.
 */
void output_osabi(unsigned char *ptr)
{
	printf("  OS/ABI:                            ");

	switch (ptr[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", ptr[EI_OSABI]);
	}
}

/**
 * output_abi - Prints the ABI version of an ELF header.
 * @ptr: A pointer to an array containing the ELF ABI version.
 */
void output_abi(unsigned char *ptr)
{
	printf("  ABI Version:                       %d\n",
	       ptr[EI_ABIVERSION]);
}

/**
 * output_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @ptr: A pointer to an array containing the ELF class.
 */
void output_type(unsigned int e_type, unsigned char *ptr)
{
	if (ptr[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * output_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @ptr: A pointer to an array containing the ELF class.
 */
void output_entry(unsigned long int e_entry, unsigned char *ptr)
{
	printf("  Entry point address:               ");

	if (ptr[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (ptr[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_e - Closes an ELF file.
 * @desc: The file descriptor of the ELF file.
 */
void close_e(int desc)
{
	if (close(desc) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", desc);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_e(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_e(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_e(header->e_ident);
	printf("ELF Header:\n");
	output_magic(header->e_ident);
	output_class(header->e_ident);
	output_data(header->e_ident);
	output_version(header->e_ident);
	output_osabi(header->e_ident);
	output_abi(header->e_ident);
	output_type(header->e_type, header->e_ident);
	output_entry(header->e_entry, header->e_ident);

	free(header);
	close_e(o);
	return (0);
}
