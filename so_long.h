/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:08:23 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 12:15:33 by jdaly            ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct s_mapdata
{
	char	**maparray;
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
	void		*mlx_ptr;
	void		*win_ptr;
	t_mapdata	mapdata;
	int			count;
	t_vec		move;
	t_img		img_floor;
	t_img		img_player;
	t_img		img_collect;
	t_img		img_wall;
	t_img		img_exit;

}	t_game;

/* 0_so_long_utils.c */
void		ft_putstr(char *str);
void		ft_putnbr(int n);
int			ft_strcmp(const char *s1, const char *s2);
int			strlen_no_newline(char *str);
char		*ft_strdup(const char *s1);

/* 0_errors.c */
void		error(char *message);
void		free_array(char **array);
void		free_error(char *message, char **array);
void		check_last_row(t_mapdata *data);

/* 1_openmap.c */
void		check_filetype(int argc, char *mapfile);
int			count_rows(char *mapfile);
char		**alloc_map(char *mapfile, int rowcount);
char		**create_map_array(char *mapfile, int rowcount);
void		init_mapdata(t_mapdata *data, char *mapfile);

/* 2_checkmap.c */
bool		check_char(char c);
void		component_count(char c, t_mapdata *data, int row, int column);
void		check_component(t_mapdata *data);
bool		check_border(char c, t_mapdata *data, int row, int column);
void		check_map_all(t_mapdata *data);

/* 3_floodfill.c */
char		**dup_map(t_mapdata *data);
void		floodfill(char **array, t_mapdata *data, int x, int y);
void		check_path(t_mapdata *data);

/* 4_renderwindow.c */
void		create_images(t_game *gdata);
void		render_map(t_game *gdata, int x, int y);
void		render_all(t_game *gdata);

/* 5_movekeyhandlers.c */
int			validate_move(t_game *gdata, int move_x, int move_y);
void		move(t_game *gdata, int move_x, int move_y);
int			win_close_x(t_game *gdata);
int			key_handler(int keycode, t_game *gdata);

#endif