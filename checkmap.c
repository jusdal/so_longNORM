/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:58 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/20 15:56:51 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	check_filetype(char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 5)
		printf("Invalid map file\n");
	else if (strcmp(&filename[len - 4], ".ber") != 0)
		printf("Invalid map file. Use a .ber file\n");
}

void	create_map_array(char *filename)
{
	int fd;
	char	*filepath;

	fd = open(filename, O_RDONLY);
	getnextline()
}

int	main(void)
{
	open()
	check_filetype(".ber");
	return (0);
}

