/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:58 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/21 00:57:56 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnl/get_next_line.h"

void	check_filetype(char *mapfile)
{
	int	len;

	len = strlen(mapfile);
	if (len < 5)
		printf("Invalid map file\n");
	else if (strcmp(&mapfile[len - 4], ".ber") != 0)
		printf("Invalid map file. Use a .ber file\n");
}

int	count_lines(char *mapfile)
{
	int fd;
	int readcount;
	int linecount;
	char	c;

	linecount = 1;
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
	return (linecount);
}

char **alloc_map(char *mapfile)
{
	char **maparray;
	int	linecount;

	linecount = count_lines(mapfile);
	printf("LINECOUNT IN ALLOC FUNCTION = %d\n", linecount);
	if (linecount <= 0)
		printf("Map Error. Please check file.");
	maparray = malloc(sizeof(char *) * linecount + 1);
	if (!maparray)
		return (0);
	return (maparray);
}

char	**create_map_array(char *mapfile)
{
	char **map;
	int fd;
	int i = 0;
	int linecount;

	linecount = count_lines(mapfile);
	map = alloc_map(mapfile);
	fd = open(mapfile, O_RDONLY);
	if (!fd)
		return (0);
	while (linecount > 0)
	{
		map[i] = get_next_line(fd);
		i++;
		linecount--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(void)
{
	char **maparray;
	int	linecount;

	linecount = count_lines("./test.ber");
	printf("Line count: %d\n", linecount);
	maparray = create_map_array("./test.ber");
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







  	return 0;
}
