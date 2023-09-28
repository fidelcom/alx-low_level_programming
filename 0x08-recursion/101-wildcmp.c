#include "main.h"

/**
 * wildcmp - compare if string with wildcard mattches
 * @s1: string to compare
 * @s2: string to compare
 * Return: 1 if matched, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
	{
		while (*(s2 + 1) == '*')
		{
			s2++;
		}
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2 + 1))
			{
				return (1);
			}
			s1++;
		}
		return wildcmp(s1, s2 + 1);
	}
		if (*s1 == *s2 || *s2 == '?')
		{
			return (wildcmp(s1 + 1, s2 + 1));
		}
		return (0);
}
