/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/01 18:40:09 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fn_checknl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*readfd(int fd, char *stash)
{
	char	*buf;
	int		nread;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread < 0)
		{
			free(buf);
			buf = NULL;
			free(stash);
			stash = NULL;
			return (0);
		}
		buf[nread] = '\0';
		stash = ft_strjoin(stash, buf);
		if (fn_checknl(buf))
			break ;
	}
	free(buf);
	return (stash);
}

char	*createline(char *stash, int linelength)
{
	char	*line;

	if (!stash)
		return (0);
	line = malloc(sizeof(char) * (linelength + 1));
	if (!line)
		return (0);
	ft_strlcpy(line, stash, linelength + 1);
	return (line);
}

char	*keep(char *stash, int linelength)
{
	char	*temp;

	if (stash[linelength - 1] == '\0')
	{
		free(stash);
		return (0);
	}
	else
	{
		temp = malloc(sizeof(char) * ft_strlen(&stash[linelength - 1]));
		if (!temp)
			return (0);
		ft_strlcpy(temp, &stash[linelength], ft_strlen(&stash[linelength - 1]));
		free(stash);
		return (temp);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			linelength;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	stash = readfd(fd, stash);
	if (!stash)
		return (0);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (0);
	}
	linelength = fn_getlength(stash) + 1;
	line = createline(stash, linelength);
	stash = keep(stash, linelength);
	return (line);
}

/*int	main(void)
{
	int     fd;
    char	*line;
	fd = open("poem.txt", O_RDONLY);
	line = get_next_line(fd);
    while (line)
	{
		printf("%s\n",line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}*/