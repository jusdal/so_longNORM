/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_renderwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:58:32 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 17:46:49 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_game *gdata)
{
	int	height;

	height = 64;
	gdata->img_collect.height = 32;
	gdata->img_collect.img = mlx_xpm_file_to_image(gdata->mlx_ptr, \
			"img/star32.xpm", &gdata->img_collect.height, \
			&gdata->img_collect.height);
	gdata->img_player.img = mlx_xpm_file_to_image(gdata->mlx_ptr, \
			"img/astro64.xpm", &height, &height);
	gdata->img_floor.img = mlx_xpm_file_to_image(gdata->mlx_ptr, \
			"img/moon64.xpm", &height, &height);
	gdata->img_wall.img = mlx_xpm_file_to_image(gdata->mlx_ptr, \
			"img/rock64.xpm", &height, &height);
	gdata->img_exit.img = mlx_xpm_file_to_image(gdata->mlx_ptr, \
			"img/rocket64.xpm", &height, &height);
}

void	render_map(t_game *gdata, int row, int col)
{
	while (row < gdata->mapdata.height)
	{
		col = 0;
		while (col < gdata->mapdata.width)
		{
			mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
					gdata->img_floor.img, col * 64, row * 64);
			if (gdata->mapdata.maparray[row][col] == 'C')
				mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
					gdata->img_collect.img, col * 64 + 16, row * 64 + 16);
			if (gdata->mapdata.maparray[row][col] == 'P')
				mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
					gdata->img_player.img, col * 64, row * 64);
			if (gdata->mapdata.maparray[row][col] == '1')
				mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
					gdata->img_wall.img, col * 64, row * 64);
			if (gdata->mapdata.maparray[row][col] == 'E')
				mlx_put_image_to_window(gdata->mlx_ptr, gdata->win_ptr, \
					gdata->img_exit.img, col * 64, row * 64);
			col++;
		}
		row++;
	}
}

void	render_all(t_mapdata mapdata)
{
	t_game	gamedata;

	gamedata.mapdata = mapdata;
	gamedata.mlx_ptr = mlx_init();
	if (!gamedata.mlx_ptr)
		free_error("MiniLibX Error", gamedata.mapdata.maparray);
	gamedata.win_ptr = mlx_new_window(gamedata.mlx_ptr, gamedata.mapdata.width \
			* 64, gamedata.mapdata.height * 64, "SO LOOOONG!");
	if (!gamedata.win_ptr)
		free_error("MiniLibX Error", gamedata.mapdata.maparray);
	create_images(&gamedata);
	render_map(&gamedata, 0, 0);
	mlx_hook(gamedata.win_ptr, 17, 1L << 0, win_close_x, &gamedata);
	mlx_key_hook(gamedata.win_ptr, key_handler, &gamedata);
	mlx_loop(gamedata.mlx_ptr);
}
