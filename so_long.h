/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:08:23 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 15:39:42 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include "key.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h> //remove
# include <string.h> //remove and replace strcmp in 1checkmap.c


typedef struct s_vector
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_img
{
	void	*img;
	int		height;
	int 	width;
}	t_img;

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
	int			count;
	t_vec		move;
	t_img		img_floor;
	t_img		img_player;
	t_img		img_collect;
	t_img		img_wall;
	t_img		img_exit;

}	t_game;

/* mapchecker.c */
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	error(char *message);
void	free_array(char **array);
void	free_error(char *message, char** array);
int		strlen_no_newline(char *str);
void	check_filetype(int argc, char *mapfile);
int		count_rows(char *mapfile);
char	**alloc_map(char *mapfile, int rowcount);
char	**create_map_array(char *mapfile, int rowcount);
void	init_mapdata(t_mapdata *data, char *mapfile);
bool	check_component(char c);
void	component_count(char c, t_mapdata *data, int row, int column);
void	component_check(t_mapdata *data);
bool	check_border(char c, t_mapdata *data, int row, int column);
void	check_map_all(t_mapdata *data);


/* flood fill.c */
char		**dup_map(t_mapdata *data);
void		fill(char **array, t_mapdata *data, int x, int y);
void		ff_map(char **array, t_mapdata *data);
void		check_path(t_mapdata *data);

/* renderwindow.c */
void	create_images(t_game *gdata);
void	init_gamedata(t_game *gdata, t_mapdata mdata);
void    render_map(t_game *gdata);
void    render_all(t_mapdata mapdata);

/* keyhandlers.c */
int win_close_x(t_game *gdata);
int key_handler(int keycode, t_game *gdata);

/* move.c */
int		validate_move(t_game *gdata, int move_x, int move_y);
void    move(t_game *gdata, int move_x, int move_y);

#endif