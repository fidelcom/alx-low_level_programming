#include "main.h"

/**
 * __exit - prints error messages and exits with exit value
 * @error: num is either exit value or file descriptor
 * @s: str is a name, either of the two filenames
 * @desc: file descriptor
 * Return: 0 on success
 **/
int __exit(int error, char *s, int desc)
{
	switch (error)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(error);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", s);
		exit(error);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", s);
		exit(error);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", desc);
		exit(error);
	default:
		return (0);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument
 * @argv: array argument
 * Return: 0 (success), 97-100 (exit value errors)
 */
int main(int argc, char *argv[])
{
	int desc_1, desc_2, reader, wrotes;
	char *buffer[1024];

	if (argc != 3)
		__exit(97, NULL, 0);

	desc_2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (desc_2 == -1)
		__exit(99, argv[2], 0);

	desc_1 = open(argv[1], O_RDONLY);
	if (desc_1 == -1)
		__exit(98, argv[1], 0);

	while ((reader = read(desc_1, buffer, 1024)) != 0)
	{
		if (reader == -1)
			__exit(98, argv[1], 0);

		wrotes = write(desc_2, buffer, reader);
		if (wrotes == -1)
			__exit(99, argv[2], 0);
	}

	close(desc_2) == -1 ? (__exit(100, NULL, desc_2)) : close(desc_2);
	close(desc_1) == -1 ? (__exit(100, NULL, desc_1)) : close(desc_1);
	return (0);
}
