/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:08:23 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/30 18:00:47 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
//# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h> //remove and replace strcmp in 1checkmap.c


typedef struct s_vector
{
	int	x;
	int	y;
} t_vec;

typedef	struct s_mapdata
{
	char 	**maparray;
	int		width;
	int		height;
	t_vec	player;
	t_vec	exit;
	int		n_player;
	int		n_exit;
	int		n_collect;
}	t_mapdata;

typedef struct s_game
{
	void 		*mlx_ptr;
	void 		*win_ptr;
	t_mapdata	mapdata;

}	t_game;

/* mapchecker.c */
void	error(char *message);
void	free_array(char **array);
void	free_error(char *message, char** array);

/* flood fill.c */
void	fill(char **array, t_mapdata *data, int x, int y);
void	ff_map(char **array, t_mapdata *data);
void	check_path(t_mapdata *data);

/* minilibx.c */


#endif