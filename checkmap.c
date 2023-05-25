/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:58 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/26 02:15:22 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gnl/get_next_line.h"


/* define data types and structs */

typedef	struct s_mapcheckerdata
{
	int	width;
	int	height;
	int	point_x;
	int	point_y;
	int	n_player;
	int	n_exit;
	int	n_collect;
}	t_mapcheckerdata;

/* check file type */
void	error(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	check_filetype(int argc, char *mapfile)
{
	int	len;

	if (argc != 2)
		error("Please inlcude 1 .ber map file as an argument.\n"));

	else if (argc == 2)
	{
		len = ft_strlen(mapfile);
		if (strcmp(&mapfile[len - 4], ".ber") != 0)
			error("Invalid map file. Use a .ber file\n"));
	}
	return (true);
}

/* create 2d array from .ber file */
int	count_rows(char *mapfile)
{
	int fd;
	int readcount;
	int rowcount;
	char	c;

	rowcount = 1;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			rowcount++;
	}
	close(fd);
	return (rowcount);
}

char **alloc_map(char *mapfile, int rowcount)
{
	char **maparray;

	printf("LINECOUNT IN ALLOC FUNCTION = %d\n", rowcount);
	if (rowcount <= 0)
		error("Map Error. Please check file.");
	maparray = malloc(sizeof(char *) * rowcount + 1);
	if (!maparray)
		return (0);
	return (maparray);
}

char	**create_map_array(char *mapfile, int rowcount)
{
	char **map;
	int fd;
	int i = 0;

	map = alloc_map(mapfile, rowcount);
	fd = open(mapfile, O_RDONLY);
	if (!fd)
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
bool	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' )
		return (true);
	else
		return (false);
}

/*void component_count(char *mapfile, char c, t_mapcheckerdata data)
{
	int fd;
	int readcount;
	char	c;

	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
}if (c == 'C')
		data.n_collect++;
	if (c == 'E')
		data.n_exit++;
	if (c == 'P')
		data.n_player++;
}*/

bool	check_border(char c, int width, int height, int point_x, int point_y)
{
	if (point_x == 0 || point_y == 0 || point_x == width - 1 || point_y == height - 1)
	{
		if (c != '1')
			return (false);
	}
	return (true);
}

void	check_map_all(t_mapcheckerdata maparray)
{
	int i;
	int j;

	i = 0;
	while (i < )
}

int	main(void)
{
	char **maparray;
	int	rowcount;

	if (check_filetype(2, "./test.ber"))
		printf("File type correct!\n");
	rowcount = count_rows("./test.ber");
	printf("Line count: %d\n", rowcount);
	maparray = create_map_array("./test.ber", rowcount);

	t_mapcheckerdata data;
	data.width = ft_strlen(maparray[0]);
	data.height = count_rows("./test.ber");
	data.point_x = 0;
	data.point_y = 0;
	data.n_player = 0;
	data.n_exit = 0;
	data.n_collect = 0;

	printf("maparray[0][0] = %c\n", maparray[0][0]);
	printf("maparray[0][1] = %c\n", maparray[0][1]);
	printf("maparray[0][2] = %c\n", maparray[0][2]);
	printf("maparray[0][3] = %c\n", maparray[0][3]);
	printf("maparray[0][4] = %c\n", maparray[0][4]);
	printf("\n");

	printf("maparray[1][0] = %c\n", maparray[1][0]);
	printf("maparray[1][1] = %c\n", maparray[1][1]);
	printf("maparray[1][2] = %c\n", maparray[1][2]);
	printf("maparray[1][3] = %c\n", maparray[1][3]);
	printf("maparray[1][4] = %c\n", maparray[1][4]);
	printf("\n");

	printf("maparray[2][0] = %c\n", maparray[2][0]);
	printf("maparray[2][1] = %c\n", maparray[2][1]);
	printf("\n");

	printf("maparray[3][0] = %c\n", maparray[3][0]);
	/*printf("data.bplayer before CHECKONE: %d\n", data.b_player);
	check_one(maparray[0][1], '1', &data.b_player);
	printf("data.bplayer after CHECKONE: %d\n", data.b_player);*/
	printf("data.width: %d\n", data.width);
	printf("data.height: %d\n", data.height);
	printf("data.point_x: %d\n", data.point_x);
	printf("map[0] = %s\n", maparray[0]);


  	return 0;
}
