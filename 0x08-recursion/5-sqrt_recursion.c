#include "main.h"

/**
 * _sqrt_helper - A helper function to calculate the square root recursively.
 * @n: The input number.
 * @guess: The current guess for the square root.
 * Return: The square root of n, or -1 if not found.
*/

int _sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The input number.
 * Return: The square root of n, or -1 if n does not have a natural square root.
*/

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt_helper(n, 0));
}
