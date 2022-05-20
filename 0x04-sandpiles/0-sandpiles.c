#include "sandpiles.h"

/**
 * print_grid - print grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grip - copy a grid
 * @grid_result: Left grid
 * @grid_sum: Right grid
 *
 */
void copy(int grid_result[3][3], int grid_sum[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_result[i][j] = grid_sum[i][j];
}

/**
 * toppling_round - Toopling
 * @grid1: 3x3 grid
 *
 */
void toppling(int grid1[3][3])
{
	int i, j;
	int stable = 1;
	int grid_copy[3][3];

	copy_grip(grid_copy, grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid_copy[i][j] >= 4)
				grid1[i][j] = grid_copy[i][j] - 4;
			if (i + 1 <= 2 && grid_copy[i + 1][j] >= 4)
				grid1[i][j] += 1;
			if (i - 1 >= 0 && grid_copy[i - 1][j] >= 4)
				grid1[i][j] += 1;
			if (j + 1 <= 2 && grid_copy[i][j + 1] >= 4)
				grid1[i][j] += 1;
			if (j - 1 >= 0 && grid_copy[i][j - 1] >= 4)
				grid1[i][j] += 1;
			if (grid1[i][j] >= 4)
				stable = 0;
		}
	}
	if (stable == 0)
	{
		printf("=\n");
		print_grid(grid1);
		toppling_round(grid1);
	}
}
/**
 * sandpiles_sum - Computes 2 sandpiles
 * @grid1: Left grid
 * @grid2: Right grid
 *
 */
void sandpiles(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] >= 4)
				stable = 0;
		}
	}
	if (stable == 0)
	{
		printf("=\n");
		print_grid(grid1);
		toppling_round(grid1);
	}
}
