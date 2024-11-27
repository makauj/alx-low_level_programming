#!/usr/bin/python3
"""_summary_
    this function returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Args:
    grid (list of list of int): A rectangular grid of 0s and 1s,
    where 1 represents land and 0 represents water.

    Returns:
    int: The perimeter of the island formed by 1s in the grid.

    The grid is guaranteed to be surrounded by water,
    and the island formed by the 1s will not contain any "lakes"
    (water cells surrounded by land cells).
    """
    perimeter = 0  # Perimeter of the island

    # Iterate through each cell in the grid
    for i in range(len(grid)):
        # Iterate through the columns of each row
        for j in range(len(grid[i])):
            # Check if current cell is land (1)
            if grid[i][j] == 1:
                # Each land cell has 4 potential edges
                # Check if the adjacent cell is water (0) or out of bounds,
                # then increase the perimeter
                if i == 0 or grid[i - 1][j] == 0:  # Top edge
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:  # Bottom edge
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:  # Left edge
                    perimeter += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:  # Right edge
                    perimeter += 1

    return perimeter
