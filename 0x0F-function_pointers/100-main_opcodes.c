#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - function that print the opcodes
 * @number_bytes: number of bytes to print
 */
void print_opcodes(int number_bytes)
{
	unsigned char *ptr = (unsigned char *)print_opcodes;
	int i;

	for (i = 0; i < number_bytes; i++)
	{
		printf("%.2x", ptr[i]);
		if (i < number_bytes - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * main - program that prints the opcodes of its own main function.
 * @argc: argument
 * @argv: array argument
 *
 * Return: always O
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes(num_bytes);

	return (0);
}
