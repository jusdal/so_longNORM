/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_floodfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:01:39 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 16:07:02 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_array(char **arr, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_putstr("\n-----------\n");
}

char	**dup_map(t_mapdata *data)
{
	int		row;
	char	**mapdup;

	mapdup = malloc(sizeof(char *) * (data->height + 1));
	if (!mapdup)
		error("Malloc Error\n");
	row = 0;
	while (data->maparray[row])
	{
		mapdup[row] = ft_strdup(data->maparray[row]);
		row++;
	}
	print_array(mapdup, data->height, data->width);
	mapdup[row] = 0;
	return (mapdup);
}

void	floodfill(char **array, t_mapdata *data, int column, int row)
{
	if (column < 0 || column >= data->width || row < 0 \
			|| row >= data->height || array[row][column] == '1')
		return ;
	array[row][column] = '1';
	floodfill(array, data, column - 1, row);
	floodfill(array, data, column + 1, row);
	floodfill(array, data, column, row - 1);
	floodfill(array, data, column, row + 1);
	return ;
}

void	check_path(t_mapdata *data)
{
	char	**mapdup;
	int		row;
	int		col;

	mapdup = dup_map(data);
	floodfill(mapdup, data, data->player.x, data->player.y);
	print_array(mapdup, data->height, data->width);
	row = 0;
	while (mapdup[row])
	{
		col = 0;
		while (col < data->width)
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
