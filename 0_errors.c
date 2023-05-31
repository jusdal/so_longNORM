/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:05:00 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 16:45:46 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	exit(EXIT_FAILURE);
}


void	free_error(char *message, char **array)
{
	free_array(array);
	error(message);
}