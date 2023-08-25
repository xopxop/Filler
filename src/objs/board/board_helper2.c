/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/08/25 12:49:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static int chebyshev_distance(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	if (dx >= dy)
		return dx;
	return dy;
}

static void map_distance_from_cell(int **map, int x1, int y1, unsigned int height, unsigned int width)
{
	int x;
	int y;
	int temp_distance;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] >= 0)
			{
				temp_distance = chebyshev_distance(x1, y1, x, y);
				if (map[y][x] == 0 || temp_distance < map[y][x])
					map[y][x] = temp_distance;
			}
			x++;
		}
		y++;
	}
}

static void map_distance_from_block(int **map, int height, int width)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == -1)
				map_distance_from_cell(map, x, y, height, width);
			x++;
		}		
		y++;
	}
}

static void map_pre_fill(int **map, char **data, int height, int width)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (data[y][x] == 'o')
				map[y][x] = -2;
			else if (data[y][x] == 'x')
				map[y][x] = -1;
			else if (data[y][x] == '.')
				map[y][x] = 0;
			x++;
		}
		y++;
	}
}

int **get_map(char **data, unsigned int height, unsigned int width)
{
	int index;
	int	**map;

	index = 0;
	map = (int **)malloc(sizeof(int *) * height);
	while (index < height)
		map[index++] = (int *)malloc(sizeof(int) * width);
	map_pre_fill(map, data, height, width);
	map_distance_from_block(map, height, width);
	return (map);
}

int main()
{
	int row = 16;
	int col = 10;
	char map[16][10] = {
		{'.', 'o', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'o', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'o', 'o', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'o', 'o', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'o', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'o', 'o', 'o', '.', '.', '.', '.', '.'},
		{'.', '.', 'o', '.', 'o', 'o', '.', '.', '.', '.'},
		{'.', '.', 'o', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', 'o', '.', 'x', '.', '.', '.', '.', '.'},
		{'.', '.', 'o', '.', 'x', 'x', '.', '.', '.', '.'},
		{'.', '.', '.', '.', 'x', 'x', 'x', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', 'x', 'x', '.', '.'},
		{'.', '.', '.', '.', '.', '.', 'x', 'x', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
	};

	char *ptr[row];
	for (int i = 0; i < row; i++)
		ptr[i] = map[i];

	int **heat_map = get_map(ptr, row, col);
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if (heat_map[y][x] < 0)
				printf(" %d ", heat_map[y][x]);
			else
				printf("  %d ", heat_map[y][x]);
		}
		printf("\n");
	}
}