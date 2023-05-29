/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:08:23 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/29 12:12:07 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
//# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


typedef struct s_vector
{
	int	x;
	int	y;
} t_vec;
typedef	struct s_mapdata
{
	int		width;
	int		height;
	int		point_row;
	int		point_column;
	t_vec	player;
	t_vec	exit;
	int		n_player;
	int		n_exit;
	int		n_collect;
}	t_mapdata;

/* mapchecker.c */
void	error(char *message);
void	free_array(char **array);
void	free_error(char *message, char** array);

/* flood fill.c */
void	fill(char **array, t_mapdata *data, int x, int y);
void	ff_map(char **maparray, t_mapdata *data);
void	check_path(char **maparray, t_mapdata *data);

/* minilibx.c */


#endif