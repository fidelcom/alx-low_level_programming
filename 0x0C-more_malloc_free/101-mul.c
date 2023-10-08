#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - function to get length of a string.
 * @s: string to evaluate.
 *
 * Return: String length.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * char_array - function to create array of chars
 * @size: The size of the array to be initialized.
 * Return: A pointer to the array.
 */
char *char_array(int size)
{
	char *arr;
	int i;

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		exit(98);

	for (i = 0; i < (size - 1); i++)
		arr[i] = '0';

	arr[i] = '\0';

	return (arr);
}

/**
 * get_val - function to get non zero
 * @s: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *get_val(char *s)
{
	while (*s && *s == '0')
		s++;

	return (s);
}

/**
 * _atoi - function that changes char to int.
 * @c: character.
 * Return: integer value.
 */
int _atoi(char c)
{
	int n = c - '0';

	if (n < 0 || n > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (n);
}

/**
 * _mul - function that multiply an input with a constant value
 * @result: store the result.
 * @n: string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 */
void _mul(char *result, char *n, int digit, int zeroes)
{
	int len, num, val = 0;

	len = _strlen(n) - 1;
	n += len;

	while (*result)
	{
		*result = 'x';
		result++;
	}

	result--;

	while (zeroes--)
	{
		*result = '0';
		result--;
	}

	for (; len >= 0; len--, n--, result--)
	{
		if (*n < '0' || *n > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*n - '0') * digit;
		num += val;
		*result = (num % 10) + '0';
		val = num / 10;
	}

	if (val)
		*result = (val % 10) + '0';
}

/**
 * sum_nums - sum numbers stored in two strings.
 * @result: result of the sum.
 * @sum: sum to be added.
 * @len: length.
 */
void sum_nums(char *result, char *sum, int len)
{
	int num, val = 0;

	while (*(result + 1))
		result++;

	while (*(sum + 1))
		sum++;

	for (; *result != 'x'; result--)
	{
		num = (*result - '0') + (*sum - '0');
		num += val;
		*result = (num % 10) + '0';
		val = num / 10;

		sum--;
		len--;
	}

	for (; len >= 0 && *sum != 'x'; len--)
	{
		num = (*sum - '0');
		num += val;
		*result = (num % 10) + '0';
		val = num / 10;

		result--;
		sum--;
	}

	if (val)
		*result = (val % 10) + '0';
}

/**
 * main - function that multiply two positive numbers.
 * @argv: array argument.
 * @argc: argument.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *result, *p;
	int size, i, n, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = get_val(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = get_val(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = _strlen(argv[1]) + _strlen(argv[2]);
	result = char_array(size + 1);
	p = char_array(size + 1);

	for (i = _strlen(argv[2]) - 1; i >= 0; i--)
	{
		n = _atoi(*(argv[2] + i));
		_mul(p, argv[1], n, zeroes++);
		sum_nums(result, p, size - 1);
	}
	for (i = 0; result[i]; i++)
	{
		if (result[i] != 'x')
			putchar(result[i]);
	}
	putchar('\n');

	free(p);
	free(result);

	return (0);
}
