#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - Checks if a integer is a palindrome
 * @n: Integer to evaluate
 *
 * Return:  return 1 if n is a palindrome 0 otherwise
 */

int is_palindrome(unsigned long int n)
{
	char buffer[20];
	int amount_of_digits, i;

	amount_of_digits = sprintf(buffer, "%lu", n);
	for (i = 0; i < amount_of_digits / 2; i++)
	{
		if (buffer[i] != buffer[amount_of_digits - i - 1])
			return (0);
	}
	return (1);
}
