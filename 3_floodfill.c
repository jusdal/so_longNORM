/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_floodfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:01:39 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 19:47:16 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mapdup[row] = 0;
	return (mapdup);
}

void	fill(char **array, t_mapdata *data, int column, int row)
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

void	ff_map(char **array, t_mapdata *data)
{
	fill(array, data, data->player.x, data->player.y);
}

void	check_path(t_mapdata *data)
{
	char	**mapdup;
	int		row;
	int		col;

	mapdup = dup_map(data);
	ff_map(mapdup, data);
	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (data->maparray[col])
		{
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
