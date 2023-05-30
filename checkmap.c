/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:58 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/30 18:19:52 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "so_long.h"

/* define data types and structs
typedef struct s_vector
{
	int	x;
	int	y;
} t_vec;
typedef	struct s_mapdata
{
	int		width;
	int		height;
	t_vec	player;
	t_vec	exit;
	int		n_player;
	int		n_exit;
	int		n_collect;
}	t_mapdata;*/

/* helper functions */
void	error(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_error(char *message, char **array)
{
	free_array(array);
	error(message);
}

int	strlen_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/* check file type */

void	check_filetype(int argc, char *mapfile)
{
	int	len;

	if (argc != 2)
		error("Please inlcude 1 .ber map file as an argument.\n");
	len = strlen(mapfile);
	if (strcmp(&mapfile[len - 4], ".ber") != 0)
		error("Invalid map file. Use a .ber file\n");
}

/* create 2d array from .ber file */
int	count_rows(char *mapfile)
{
	int		fd;
	int		readcount;
	int		rowcount;
	char	c;

	rowcount = 1;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			rowcount++;
	}
	close(fd);
	return (rowcount);
}

char	**alloc_map(char *mapfile, int rowcount)
{
	char	**maparray;

	(void)mapfile;
	if (rowcount <= 2)
		error("Map Error. Please check file.");
	maparray = malloc(sizeof(char *) * (rowcount + 1));
	if (!maparray)
		error("Malloc Error");
	return (maparray);
}

char	**create_map_array(char *mapfile, int rowcount)
{
	char	**map;
	int		fd;
	int 	i;

	i = 0;
	map = alloc_map(mapfile, rowcount);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (0);
	while (rowcount > 0)
	{
		map[i] = get_next_line(fd);
		i++;
		rowcount--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/* check map values */
void	init_mapdata(t_mapdata *data, char *mapfile)
{
	data->width = strlen_no_newline(data->maparray[0]);
	data->height = count_rows(mapfile);
	data->n_player = 0;
	data->n_exit = 0;
	data->n_collect = 0;
}

bool	check_component(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' )
		return (true);
	else
		return (false);
}

void	component_count(char c, t_mapdata *data, int row, int column)
{
	if (c == 'C')
		data->n_collect++;
	if (c == 'E')
	{
		data->n_exit++;
		data->exit.x = column;
		data->exit.y = row;
	}
	if (c == 'P')
	{
		data->n_player++;
		data->player.x = column;
		data->player.y = row;
	}
}

void	component_check(t_mapdata *data)
{
	if (data->n_collect < 1)
		free_error("Map must contain at least 1 collectable", data->maparray);
	if (data->n_player != 1)
		free_error("Map must contain only 1 player", data->maparray);
	if (data->n_exit != 1)
		free_error("Map must contain only 1 exit", data->maparray);
}

bool	check_border(char c, t_mapdata *data, int row, int column)
{
	if (row == 0 || column == 0 || row == data->height - 1 || column == data->width - 1)
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

	row = 0;
	while (row < data->height)
	{
		if (strlen_no_newline(data->maparray[row]) != data->width)
			free_error("Map must be rectangular", data->maparray);
		col = 0;
		while (data->maparray[col])
		{
			//printf("point = %c\n", maparray[row][column]);
			if (!check_component(data->maparray[row][col]))
				free_error("Invalid character in map. Please use only 1, 0, P, E, C", data->maparray);
			if (!check_border(data->maparray[row][col], data, row, col))
				free_error("Check that map border contains all 1s", data->maparray);
			component_count(data->maparray[row][col], data, row, col);
			col++;
		}
		row++;
	}
	component_check(data);
}

/* check valid path using flood fill*/


int	main(int argc, char *argv[])
{
	t_mapdata	data;

	check_filetype(argc, argv[1]);
	data.maparray = create_map_array(argv[1], count_rows(argv[1]));
	init_mapdata(&data, argv[1]);

	printf("data.width: %d\n", data.width);
	printf("data.height: %d\n", data.height);

	check_map_all(&data);

	printf("data.n_player: %d\n", data.n_player);
	printf("data.n_exit: %d\n", data.n_exit);
	printf("data.n_collect: %d\n", data.n_collect);
	printf("player is at [%d, %d]\n", data.player.x, data.player.y);
	printf("exit is at [%d, %d]\n", data.exit.x, data.exit.y);

	printf("map[0] = %s", data.maparray[0]);
	printf("map[1] = %s", data.maparray[1]);
	printf("map[2] = %s", data.maparray[2]);
	printf("map[3] = %s", data.maparray[3]);
	printf("map[4] = %s", data.maparray[4]);
	printf("map[5] = %s\n", data.maparray[5]);

	check_path(&data);
	free_array(data.maparray);
	return (0);
}
