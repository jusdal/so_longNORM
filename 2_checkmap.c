/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_checkmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:47:16 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 11:35:31 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (true);
	else
		return (false);
}

void	component_count(char c, t_mapdata *data, int row, int column)
{
	if (c == 'C')
		data->n_collect++;
	else if (c == 'E')
	{
		data->n_exit++;
		data->exit.x = column;
		data->exit.y = row;
	}
	else if (c == 'P')
	{
		data->n_player++;
		data->player.x = column;
		data->player.y = row;
	}
}

void	check_component(t_mapdata *data)
{
	if (data->n_collect < 1)
		free_error("Map must contain at least 1 collectable\n", data->maparray);
	if (data->n_player != 1)
		free_error("Map must contain only 1 player\n", data->maparray);
	if (data->n_exit < 1)
		free_error("Map must contain 1 exit\n", data->maparray);
	if (data->n_exit > 1)
		free_error("Map must comtain only 1 exit\n", data->maparray);
}

bool	check_border(char c, t_mapdata *data, int row, int column)
{
	if (row == 0 || column == 0 || row == data->height - 1 \
			|| column == data->width - 1)
	{
		if (c != '1')
			return (false);
	}
	return (true);
}

void	check_map_all(t_mapdata *data)
{
	int	col;
	int	row;

	if (strlen_no_newline(data->maparray[data->height - 1]) == 0) // check for new line at bottom of map
	{
		free(data->maparray[data->height - 1]);
		data->maparray[data->height - 1] = NULL;
		data->height--;
	}
	row = 0;
	while (row < data->height)
	{
		if (strlen_no_newline(data->maparray[row]) != data->width)
			free_error("Map must be rectangular\n", data->maparray);
		col = 0;
		while (col < data->width)
		{
			if (!check_char(data->maparray[row][col]))
				free_error("Invalid character. Please use only 1,0,P,E,C\n", \
					data->maparray);
			if (!check_border(data->maparray[row][col], data, row, col))
				free_error("Check that map border contains all 1s\n", \
					data->maparray);
			component_count(data->maparray[row][col], data, row, col);
			col++;
		}
		row++;
	}
	check_component(data);
}
