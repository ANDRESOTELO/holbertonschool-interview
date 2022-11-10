#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - auxiliary function
 * @array: array of data to be sorted
 * @buff: buffer
 * @size: size of data
 * @lsd: Less significant digit
 * Return: No Return
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int i, j, csize = 10, number;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		number = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				number = number / 10;
		number = number % 10;
		buff[number][carr[number]] = array[i];
		carr[number] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (carr[i] > 0)
		{
			array[j] = buff[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * csort - auxiliary function
 * @array: array of data
 * @size: size of data
 * @lsd: Less significant digit
 * Return: No Return
 */
void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, number, csize = 10, **buff;

	for (i = 0; i < size; i++)
	{
		number = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				number = number / 10;
		number = number % 10;
		carr[number] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (carr[i] != 0)
			buff[i] = malloc(sizeof(int) * carr[i]);

	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (carr[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: array of data
 * @size: size of data
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
