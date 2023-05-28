/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:59:47 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/11 03:05:06 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dst);
	if (i > dstsize || dstsize == 0)
		return (dstsize + ft_strlen(src));
	j = 0;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	free(s1);
	return (str);
}

int	fn_getlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
