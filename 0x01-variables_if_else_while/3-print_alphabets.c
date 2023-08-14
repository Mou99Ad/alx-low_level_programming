#include <stdio.h>

 /**
* main - Entry point
* Descp: prints alphabet in lowercase, then in uppercase uses putchar
* Return: Always 0 (Success)
 */

int main(void)
{
	char ch;

	/** Print lowercase alphabet */
	for (ch = 'a'; ch <= 'z'; ch++)
		{
		putchar(ch);
		}

	/** Print uppercase alphabet */
	for (ch = 'A'; ch <= 'Z'; ch++)
		{
		putchar(ch);
		}

	putchar('\n'); /** Print a new line */
	return (0);
}
