#include "main.h"

/**
* wildcmp - Compare 2 strings and returns 1 if they can be considered identical
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 1 if the strings are identical, otherwise 0.
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (wildcmp(s1, s2 + 1))
			return (1);
		return (wildcmp(s1 + 1, s2));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
