#include "main.h"

/**
 * alloc_grid -  return a pointer to a 2 dimensional array of integers
 *@width: width of grid
 *@height: height of grid
 *Return: grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/* Check if width or height is 0 or negative */
	if (width <= 0 || height <= 0)
		return (NULL);
	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);
	/* Allocate memory for each row and initialize to 0 */
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			return (NULL);
		}
		/* Initialize elements to 0 */
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}
