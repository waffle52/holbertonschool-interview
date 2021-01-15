#include "sandpiles.h"

/**
 * print - print grid
 * @grid: grid to print
 */
void print(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_piles - add two sandpiles together
 * @grid1: grid 1 to add to
 * @grid2: grid 2 to add to grid 1
 */
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * is_stable - check if grid is stable
 * @grid: grid to check is stable
 * Return: 1 (Stable) 0 not stable
 */
int is_stable(int grid[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}

	return (1);
}

/**
 * topple - topple a grid
 * @grid: grid to topple
 */
void topple(int grid[3][3])
{
	int i;
	int j;
	int increment[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					increment[i - 1][j]++;
				if (i < 2)
					increment[i + 1][j]++;
				if (j > 0)
					increment[i][j - 1]++;
				if (j < 2)
					increment[i][j + 1]++;
			}
		}
	}

	add_piles(grid, increment);
}

/**
 * sandpiles_sum - compute sum of two sandpiles
 * @grid1: first sandpile grid
 * @grid2: second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_piles(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		print(grid1);
		topple(grid1);
	}
}
