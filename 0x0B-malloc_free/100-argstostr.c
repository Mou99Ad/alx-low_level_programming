#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: An array of pointers to the arguments.
 * Return: Pointer to the concatenated string, or NULL if it fails.
*/

char *argstostr(int ac, char **av)
{
	char *concatenated;
	int total_length = 0;
	int i, j;
	int k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		total_length++; /** Count the newline character*/
	}
	concatenated = malloc(sizeof(char) * (total_length + 1));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			concatenated[k] = av[i][j];
			j++;
			k++;
		}
		concatenated[k] = '\n'; /** Add newline character */
		k++;
	}

	concatenated[k] = '\0'; /** Add null-terminator */

	return (concatenated);
}
