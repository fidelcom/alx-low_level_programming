#include "main.h"

int _helper_string_length(char *s);
int _check_string_helper(char *i, char *j);
/**
 * is_palindrome - function that check if a string is a palindrome or not.
 * @s: string to check
 * Return: return
 */

int is_palindrome(char *s)
{
	int len;

	len = _helper_string_length(s);
	return (_check_string_helper(s, (s + len - 1)));
}

/**
 * _check_string_helper - compares indice from the beginning of the string
 * to the that from the end check match
 * @i: start of the string
 * @j: end of the string
 * Return: 1 if true and 0 if not
 */
int _check_string_helper(char *i, char *j)
{
	if (i > j)
	{
		return (1);
	}
	if (*i == *j)
	{
		return (_check_string_helper(i + 1, j - 1));
	}
	return (0);
}

/**
 * _helper_string_length - Check the length of the string to get ending index
 * @s: string to check
 * Return: length
 */

int _helper_string_length(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (1 + _helper_string_length(s));
}
