/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/09/01 22:27:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


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