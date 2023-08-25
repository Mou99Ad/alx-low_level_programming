#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The input string.
 * Return: 1 if the string is a palindrome, 0 otherwise.
*/

int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);

	return (check_palindrome(s, 0, length - 1));
}

/**
 * check_palindrome - Helper function to check if a string is a palindrome using recursion.
 * @s: The input string.
 * @start: The starting index for comparison.
 * @end: The ending index for comparison.
 * Return: 1 if the string is a palindrome, 0 otherwise.
*/

int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}

/**
  * _strlen_recursion - Get the length of a string
  * @s: the string to get the length
  *
  * Return: the string length
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	s++;
	return (_strlen_recursion(s) + 1);
}
