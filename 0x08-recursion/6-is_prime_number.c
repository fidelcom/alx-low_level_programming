#include "main.h"

int is_prime_helper_recursion(int n, int i);
/**
 * is_prime_number - function that use to check if a number is prime number
 * @n: number to very if it is prime or not
 * Return: return result
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (is_prime_helper_recursion(n, n - 1));
}

/**
 * is_prime_helper_recursion - function the check the prime number
 * @n: number to check the prime number for
 * @i: number to determine the number of loop to perform
 * Return: return 1 if prime else 0;
 */

int is_prime_helper_recursion(int n, int i)
{
	if (i == 1)
	{
		return (1);
	}
	if (n % i == 0 && i > 0)
	{
		return (0);
	}
	return (is_prime_helper_recursion(n, i - 1));
}
