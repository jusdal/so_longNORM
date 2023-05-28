/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:01:39 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/29 00:08:08 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strdup(char *str)
{
	int		len;
	char	*ret;

	len = -1;
	while (str[++len])
		;
	ret = (char *)malloc(len + 1);
	len = 0;
	while (*str)
		ret[len++] = *str++;
	ret[len] = 0;
	return (ret);
}

char	**dup_map(char **maparray, t_mapdata *data)
{
	int		row;
	char	**mapdup;

	mapdup = malloc(sizeof(char *) * (data->height + 1));
	if (!mapdup)
		error("Malloc Error");
	row = 0;
	while (row < data->height)
	{
		mapdup[row] = ft_strdup(maparray[row]);
		row++;
	}
	mapdup[row] = 0;
	return (mapdup);
}

void	fill(char **array, t_mapdata *data, int column, int row)
{
    // Check if current position is out of bounds or a wall
    if (column < 0 || column >= data->width || row < 0 \
				|| row >= data->height || array[row][column] == '1')
        return ;

    // Mark current position as visited
    array[row][column] = '1';

    // Recursively explore adjacent positions
    fill(array, data, column - 1, row); // go left
    fill(array, data, column + 1, row); // go right
    fill(array, data, column, row - 1); // go down
    fill(array, data, column, row + 1); // go up
	return ;
}

void	ff_map(char **maparray, t_mapdata *data)
{
	fill(maparray, data, data->player.x, data->player.y);
}

void	check_path(char **maparray, t_mapdata *data)
{
	char	**mapdup;
	int 	row;
	int 	col;

	//duplicate map
	mapdup = dup_map(maparray, data);

	//fill duplicated map
	ff_map(mapdup, data);

	//check for C/E
	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (maparray[col])
		{
			if (mapdup[row][col] == 'C' || mapdup[row][col] == 'E')
			{
				free_array(mapdup);
				free_error("No valid path. Please check map", maparray);
			}
			col++;
		}
		row++;
	}
	free_array(mapdup);
}
		//if no path
			//free both maparrays
		//if path
			//free filled array