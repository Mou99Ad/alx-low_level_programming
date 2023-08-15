#include <stdio.h>

/**
* main - Entry point
* Description: Prints all possible different combinations of three digits
* Return: Always 0 (Success)
*/

int main(void)
{
	int num1, num2, num3;

	/** Iterate through the first digit */
	for (num1 = 0; num1 < 9; num1++)
	{
		/** Iterate through the second digit (greater than the first)*/
		for (num2 = num1 + 1; num2 <= 9; num2++)
		{
			/** Iterate through the third digit (greater than the second) */
			for (num3 = num2 + 1; num3 <= 9; num3++)
			{
				/** Print the three digits */
				putchar(num1 + '0');
				putchar(num2 + '0');
				putchar(num3 + '0');

				/** Print comma and space if not the last combination */
				if (num1 != 7 || num2 != 8 || num3 != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
