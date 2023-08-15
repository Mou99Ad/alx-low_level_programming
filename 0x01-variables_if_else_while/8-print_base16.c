#include <stdio.h>

/**
* main - Entry point
* Description: all the numbers of base 16 in lowercase using putchar, followed by a new line
* Return: Always 0 (Success)
*/

int main(void)
{
/** Base 16 (hexadecimal) uses digits 0-9 and letters A-F (or a-f) to represent numbers, where A stands for 10, B for 11, and so on up to F for 15 */
	int digit;
	int letter;

/** Print numbers '0' to '9' */
	for (digit = 0; digit <= 9; digit++)
	{
	putchar(digit + '0');
	}

/** Print lowercase hexadecimal characters 'a' to 'f' */
	for (letter = 'a'; letter <= 'f'; letter++)
	{
	putchar(letter);
	}

	putchar('\n');

	return 0;
}
