/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:05:00 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 12:37:29 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
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

void	check_last_row(t_mapdata *data)
{
	if (strlen_no_newline(data->maparray[data->height - 1]) == 0)
	{
		free(data->maparray[data->height - 1]);
		data->maparray[data->height - 1] = NULL;
		data->height--;
	}
}
