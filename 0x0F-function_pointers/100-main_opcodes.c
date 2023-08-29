#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 (success), 1 if incorrect number of arguments, 2 if negative bytes
*/

int main(int argc, char *argv[])
{
	int i, bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	unsigned char *main_ptr = (unsigned char *)&main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02x", main_ptr[i]);
		if (i < bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
