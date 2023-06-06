/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:55:49 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/01 18:39:09 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		fn_checknl(char *str);
int		fn_getlength(char *str);
char	*readfd(int fd, char *stash);
char	*createline(char *stash, int linelength);
char	*keep(char *stash, int linelength);
int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlcat(char *dst, const char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2);

#endif