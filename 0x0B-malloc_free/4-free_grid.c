#include "main.h"
/**
 * free_grid - free allocated memory
 * @grid: grid array
 * @height: grid height
 * Return: null
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Free each row */
	for (i = 0; i < height; i++)
		free(grid[i]);
	/* Free the array of pointers */
	free(grid);
}
