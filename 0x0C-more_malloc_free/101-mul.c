#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	len = _strlen(s);

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * _isdigit - function to checks for a digit 0 through 9
 * @c: digit to be checked
 * Return: 1 if true, 0 if false
 */

int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
	{
		if (c[i] < '0' && c[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _mul - function that multiply two numbers
 * @num1: integer
 * @num2: integer
 * Return: result
 */
int _mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * check_array - check array size
 * @a: integer
 * Return: return 1;
 */

int check_array(int a)
{
	if (a != 3)
	{
		return (0);
	}
	return (1);
}

/**
 * errors - print error
 */

void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * verify_input - verity if input are digit
 * @n2: input 1
 * @n2: input 2
 * Return: 1 or 0
 */

int verify_input(int n1, int n2)
{
	if (!_isdigit(n1) || !_isdigit(n2))
		return (0);
	return (1);
}

/**
 * main - multiply two postive integer
 * @argc: argument
 * @argv: array argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *n1, *n2;
	int num1, num2, size, *mem, i, j, a, b, c, val;

	n1 = argv[1];
	n2 = argv[2];
	if (!check_array(argc))
		errors();
	if (!verify_input(n1, n2)
			errors();
	size = _strlen(n1) + _strlen(n2) + 1;
	mem = malloc(sizeof(int) * size);
	if (mem == NULL)
		return (1);
	for (i = 0; i <= (_strlen(n1) + _strlen(n2)); i++)
		mem = 0;
	a = _strlen(n1);
	b = _strlen(n2);
	for (a = a - 1; a >= 0; a--)
	{
		num1 = n1[a] - '1';
		val = 0;
		for (b = b - 1; b >= 0; b--)
		{
			num2 = n2[b] - '0';
			val += mem[size] + _mul(num1, num2);
			mem[size] = val % 10;
			val /= 10;
		}
		if (val > 0)
			mem[size] += val;
	}
	for (j = 0; j < size - 1; j++)
	{
		if (mem[j])
		{
			_putchar(mem[j] + '0');
			c = 1;
		}
	}
	if (!c)
		_putchar('0');
	_putchar('\n');
	free(mem);
	return (0);
}
