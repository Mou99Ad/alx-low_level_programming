#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 1 on error.
*/
int main(int argc, char *argv[])
{
    /* Check if the correct number of arguments is provided */
    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    /* Check if the input numbers are valid (digits only) */
    for (int i = 0; num1[i] != '\0'; i++)
    {
        if (num1[i] < '0' || num1[i] > '9')
        {
            printf("Error\n");
            return (1);
        }
    }

    for (int i = 0; num2[i] != '\0'; i++)
    {
        if (num2[i] < '0' || num2[i] > '9')
        {
            printf("Error\n");
            return (1);
        }
    }

    int len1 = 0, len2 = 0;
    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    /* Allocate memory for the result array */
    int *result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL)
    {
        printf("Error\n");
        return (1);
    }

    /* Initialize the result array to 0 */
    for (int i = 0; i < len1 + len2; i++)
        result[i] = 0;

    /* Multiply the numbers using long multiplication */
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = (n1 * n2) + result[i + j + 1] + carry;

            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }

        if (carry)
            result[i] += carry;
    }

    /* Print the multiplied result */
    int i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;

    if (i == len1 + len2)
        putchar('0');
    else
    {
        while (i < len1 + len2)
            putchar(result[i++] + '0');
    }

    putchar('\n');
    free(result);

    return (0);
}
