#include "main.h"
/**
 * _isalpha - Checks if a character is an alphabetic character (letter)
 * @c: The character to be checked
 *
 * Return: 1 if c is a letter, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);  /** Character is a letter */
	else
		return (0);  /** Character is not a letter */
}
