#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the result of the multiplication
 * @argc: argument counter
 * @argv: numbers to multiply
 * Return: 0 on success, 1 if two arguments not given
 */

int main(int argc, char *argv[])
{

	/* check if the input is two */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* mulitply two two numbers passed as input */
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
