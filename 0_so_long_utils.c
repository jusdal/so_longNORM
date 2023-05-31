/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_so_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:41:51 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 16:52:59 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int strlen_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

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