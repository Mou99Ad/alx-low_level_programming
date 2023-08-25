#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/* Provided function to print a character */
int _putchar(char c);
/* Function to print a string followed by a new line recursively */
void _puts_recursion(char *s);
/* Function to print a string in reverse recursively */
void _print_rev_recursion(char *s);
/* Function to calculate the length of a string recursively */
int _strlen_recursion(char *s);
/* Function to calculate the factorial of a number recursively */
int factorial(int n);
/* Function to calculate x raised to the power of y recursively */
int _pow_recursion(int x, int y);
/* Function to calculate the natural square root of a number recursively */
int _sqrt_recursion(int n);
/* Function to check if a number is prime recursively */
int is_prime_number(int n);
/* Forward declaration of is_prime_helper */
int is_prime_helper(int n, int divisor);
/* Function to check if a string is a palindrome recursively */
int is_palindrome(char *s);
/* Helper function to check palindrome */
int check_palindrome(char *s, int start, int end);
/** Function to compare two strings with wildcards */
int wildcmp(char *s1, char *s2);


#endif
