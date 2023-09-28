#include "main.h"

int _sqrt_helper_recursion(int n, int i);
/**
 * _sqrt_recursion - function that returns the natural square root
 * @n: number to get the squareroot
 * Return: return squareroot
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_helper_recursion(n, 0));
}

/**
 * _sqrt_helper_recursion - function to find the squareroot of natural number
 * @n: natural number to obtain squareroot
 * @i: number of time to multiple the natural number by itself
 *
 * Return: result
 */

int _sqrt_helper_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt_helper_recursion(n, i + 1));
}
