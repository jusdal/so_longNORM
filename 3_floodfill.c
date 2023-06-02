/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_floodfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justindaly <justindaly@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:01:39 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/03 01:49:37 by justindaly       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> //remove later

void print_array(char **arr, int height, int width) 
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
	printf("-----------\n");
}

char	**dup_map(t_mapdata *data)
{
	int		row;
	char	**mapdup;

	mapdup = malloc(sizeof(char *) * (data->height + 1));
	if (!mapdup)
		error("Malloc Error\n");
	row = 0;
	while (row < data->height)
	{
		mapdup[row] = ft_strdup(data->maparray[row]);
		row++;
	}
	print_array(mapdup, data->height, data->width); //remove
	mapdup[row] = 0;
	return (mapdup);
}

void	floodfill(char **array, t_mapdata *data, int column, int row)
{
	if (column < 0 || column >= data->width || row < 0 \
			|| row >= data->height || array[row][column] == '1')
		return ;
	array[row][column] = '1';
	fill(array, data, column - 1, row);
	fill(array, data, column + 1, row);
	fill(array, data, column, row - 1);
	fill(array, data, column, row + 1);
	return ;
}

void	check_path(t_mapdata *data)
{
	char	**mapdup;
	int		row;
	int		col;

	mapdup = dup_map(data);
	floodfill(mapdup, data, data->player.x, data->player.y);
	print_array(mapdup, data->height, data->width); //remove
	printf("height = %d\n", data->height);
	printf("width = %d\n", data->width);
	row = 0;
	while (mapdup[row])
	{
		printf("map[%d] = %s\n", row, mapdup[row]);
		col = 0;
		while (col < data->width) //problem was here
		{
			printf("mapdup[%d][%d] = %c\n", row, col, mapdup[row][col]);
			if (mapdup[row][col] == 'C' || mapdup[row][col] == 'E')
			{
				free_array(mapdup);
				free_error("No valid path. Please check map\n", data->maparray);
			}
			col++;
		}
		row++;
	}
	free_array(mapdup);
}
