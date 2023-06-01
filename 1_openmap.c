/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_openmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:58 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/01 16:33:14 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filetype(int argc, char *mapfile)
{
	int	len;
	int	i;

	if (argc != 2)
		error("Please include 1 .ber map file as an argument.\n");
	len = 0;
	i = 0;
	while (mapfile[i++])
		len++;
	if (len < 4 || ft_strcmp(&mapfile[len - 4], ".ber") != 0)
		error("Invalid map file. Use a .ber file\n");
}

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
		error("Map Error. Please check file\n");
	maparray = malloc(sizeof(char *) * (rowcount + 1));
	if (!maparray)
		error("Malloc Error");
	return (maparray);
}

char	**create_map_array(char *mapfile, int rowcount)
{
	char	**map;
	int		fd;
	int		i;

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

void	init_mapdata(t_mapdata *data, char *mapfile)
{
	data->width = strlen_no_newline(data->maparray[0]);
	data->height = count_rows(mapfile);
	data->n_player = 0;
	data->n_exit = 0;
	data->n_collect = 0;
}
