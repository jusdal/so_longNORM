/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_renderwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:58:32 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 16:06:24 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *gdata)
{
	gdata->img_collect.img = NULL;
	gdata->img_player.img = NULL;
	gdata->img_floor.img = NULL;
	gdata->img_wall.img = NULL;
	gdata->img_exit.img = NULL;
}

void	create_images(t_game *gdata)
{
	gdata->img_collect.img = mlx_xpm_file_to_image(gdata->mlx_ptr,
			"img/star32.xpm", &gdata->img_collect.width,
			&gdata->img_collect.height);
	gdata->img_player.img = mlx_xpm_file_to_image(gdata->mlx_ptr,
			"img/astro64.xpm", &gdata->img_player.width,
			&gdata->img_player.height);
	gdata->img_floor.img = mlx_xpm_file_to_image(gdata->mlx_ptr,
			"img/moon64.xpm", &gdata->img_floor.width,
			&gdata->img_floor.height);
	gdata->img_wall.img = mlx_xpm_file_to_image(gdata->mlx_ptr,
			"img/rock64.xpm", &gdata->img_wall.width,
			&gdata->img_wall.height);
	gdata->img_exit.img = mlx_xpm_file_to_image(gdata->mlx_ptr,
			"img/rocket64.xpm", &gdata->img_exit.width,
			&gdata->img_exit.height);
	if (!gdata->img_collect.img || !gdata->img_player.img
		|| !gdata->img_floor.img || !gdata->img_wall.img
		|| !gdata->img_exit.img)
	{
		ft_putstr("Error\nMiniLibX Error\n");
		win_close_x(gdata);
	}
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

void	render_all(t_game *gdata)
{
	gdata->mlx_ptr = mlx_init();
	if (!gdata->mlx_ptr)
		free_error("MiniLibX Error", gdata->mapdata.maparray);
	gdata->win_ptr = mlx_new_window(gdata->mlx_ptr, gdata->mapdata.width \
			* 64, gdata->mapdata.height * 64, "SO LOOOONG!");
	if (!gdata->win_ptr)
		free_error("MiniLibX Error", gdata->mapdata.maparray);
	init_images(gdata);
	create_images(gdata);
	render_map(gdata, 0, 0);
	mlx_hook(gdata->win_ptr, 17, 0L, win_close_x, gdata);
	mlx_key_hook(gdata->win_ptr, key_handler, gdata);
	mlx_loop(gdata->mlx_ptr);
}
