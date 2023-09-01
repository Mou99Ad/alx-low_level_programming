#include "main.h"

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is an invalid char in the string
 *         or if b is NULL.
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = result << 1;
		if (*b == '1')
			result = result | 1;

		b++;
	}

	return (result);
}
