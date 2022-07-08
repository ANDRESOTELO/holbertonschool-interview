#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * check - Check indices
 * @i: Row Index
 * @j: Column Index
 * Return: 1 if (1, 1), 0 otherwise
 */

int check(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 * Return - Nothing if level is lower than 0
 */
void menger(int level)
{
	int i, j, limit;

	if (level < 0)
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			check(i, j) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
