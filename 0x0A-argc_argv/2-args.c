#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int i;

	/* Loop through all arguments and print each on a new line */
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

