#include "slide_line.h"

/**
* left_slide - slides a line to the left
* @line: array
* @size: array size
* Return: 1 on success, 0 on failure
**/
void left_slide(int *line, size_t size)
{
	size_t i = 0, j = 0, k = 0;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			for (; line[i] == 0;)
				i++;
		if (i == (size - 1))
			break;
		j = i + 1;
		if (line[j] == 0)
			for (; line[j] == 0;)
				j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];
	while (k < size)
		line[k++] = 0;
}

/**
* right_slide - slides a line to the right
* @line: array
* @size: array size
* Return: 1 on success, 0 on failure
**/
void right_slide(int *line, int size)
{
	int i, j = size - 1, sw = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	if (j >= 0)
		line[j] = 0;
	for (i = size - 1; i >= 0; i--)
	{
		if (i > j && line[i] == line[i - 1])
		{
			sw = 1;
			line[i] += line[i - 1];
			line[i - 1] = 0;
		}
		else if (i <= j)
		{
			line[i] = 0;
		}
	}
	if (sw == 1 && j >= 0)
		line[0] = 0;
	j = size - 1;
	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	for (i = 0; i <= j; i++)
		line[i] = 0;
}
/**
* slide_line - entry point slides a line either left or right
* @size: array size
* @direction: slide direction
* @line: input array
* Return: 1 on success, 0 on failure
**/
int slide_line(int *line, size_t size, int direction)
{
	int temp_size = size;

	if (direction == SLIDE_LEFT)
	{
		left_slide(line, temp_size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		right_slide(line, temp_size);
	}
	return (1);
}
