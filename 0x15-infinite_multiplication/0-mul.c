#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - Checks if a string is a number
 *
 * @s: String to check
 *
 * Return: 0 if not a number, 1 if is a number
 */
int _isnumber(char *s)
{
	int i, check, d;

	d = 0, check = 1;
	for (i = 0; *(s + i) != 0; i++)
	{
		d = isdigit(*(s + i));
		if (d == 0)
		{
			check = 0;
			break;
		}
	}
	return (check);
}

/**
 * _callocX - Allocate memory0
 *
 * @nmemb: Number of bytes
 *
 * Return: A pointer
 */
char *_callocX(unsigned int nmemb)
{
	unsigned int i;
	char *p;

	p = malloc(nmemb + 1);
	if (p == 0)
		return (0);
	for (i = 0; i < nmemb; i++)
		p[i] = '0';
	p[i] = '\0';
	return (p);
}

/**
 * main - Multiplies numbers
 *
 * @argc: Number of command line args
 * @argv: Command line arg
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	int i, j, l1, l2, lful, mul, add, ten, ten2, tl, zer = 0;
	char *res;

	if (argc != 3 || _isnumber(argv[1]) == 0 || _isnumber(argv[2]) == 0)
		printf("Error\n"), exit(98);
	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		printf("0\n"), exit(0);
	l1 = strlen(argv[1]), l2 = strlen(argv[2]);
	lful = l1 + l2;
	res = _callocX(lful);
	if (res == 0)
		printf("Error\n"), exit(98);
	for (i = l2 - 1; i >= 0; i--)
	{
		ten = 0, ten2 = 0;
		for (j = l1 - 1; j >= 0; j--)
		{
			tl = i + j + 1;
			mul = (argv[1][j] - '0') * (argv[2][i] - '0') + ten;
			ten = mul / 10;
			add = (res[tl] - '0') + (mul % 10) + ten2;
			ten2 = add / 10;
			res[tl] = (add % 10) + '0';
		}
		res[tl - 1] = (ten + ten2) + '0';
	}
	if (res[0] == '0')
		zer = 1;
	for (; zer < lful; zer++)
		printf("%c", res[zer]);
	printf("\n");
	free(res);
	return (0);
}
