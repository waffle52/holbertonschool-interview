#include "slide_line.h"

/**
 * slide_line - entry
 * @line: an array of ints
 * @size: size of line
 * @direction: Which direction to shift
 *
 * Return: 1 (SUCCESS) 0 (FAIL)
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (left(line, size));
	return (right(line, size));
}

/**
 * left - left shift
 * @line: an array of ints
 * @size: size of line
 *
 * Return: 1 (SUCCESS) 0 (FAIL)
 */
int left(int *line, size_t size)
{
	int num = 0;
	int num1 = 0;
	size_t count = 0;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && num == 0)
			num = line[i];
		else if (line[i] != 0 && num != 0)
			num1 = line[i];
		if (num != 0 && num1 != 0)
		{
			if (num == num1)
			{
				line[count++] = num + num1;
				num = 0;
				num1 = 0;
			}
			else
			{
				line[count++] = num;
				num = num1;
				num1 = 0;
				if (i == size - 1)
					line[count++] = num;
			}
		}
		else if (num != num1 && i == size - 1)
			line[count++] = num;
	}
	for (i = count; i < size; i++)
	{
		line[i] = 0;
	}
	return (1);
}
/**
 * right - right shift
 * @line: an array of ints
 * @size: size of line
 *
 * Return: 1 (SUCCESS) 0 (FAIL)
 */
int right(int *line, size_t size)
{
	int num = 0;
	int num1 = 0;
	size_t count = size - 1;
	size_t i = 0;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && num == 0)
			num = line[i];
		else if (line[i] != 0 && num != 0)
			num1 = line[i];
		if (num != 0 && num1 != 0)
		{
			if (num == num1)
			{
				line[count--] = num + num1;
				num = 0;
				num1 = 0;
			}
			else
			{
				line[count--] = num;
				num = num1;
				num1 = 0;
				if (i == 0)
					line[count--] = num;
			}
		}
		else if (num != num1 && i == 0)
			line[count--] = num;
	}
	for (i = 0; i < count; i++)
	{
		line[i] = 0;
	}
	return (1);
}
