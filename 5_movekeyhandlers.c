/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_movekeyhandlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:30:17 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/06 17:41:07 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key.h"

int	validate_move(t_game *gdata, int move_x, int move_y)
{
	char	pos;

	pos = gdata->mapdata.maparray[move_y][move_x];
	if (pos == 'C')
	{
		gdata->mapdata.n_collect--;
		return (2);
	}
	else if (pos == 'E' && gdata->mapdata.n_collect == 0)
	{
		ft_putstr("*****YOU WIN*****\n");
		return (3);
	}
	else if (pos == 'E' || pos == '0')
		return (1);
	else
		return (0);
}

void	move(t_game *gdata, int move_x, int move_y)
{
	if (gdata->mapdata.player.x == gdata->mapdata.exit.x && \
			gdata->mapdata.player.y == gdata->mapdata.exit.y)
		gdata->mapdata.maparray[gdata->mapdata.player.y] \
			[gdata->mapdata.player.x] = 'E';
	else
		gdata->mapdata.maparray[gdata->mapdata.player.y] \
			[gdata->mapdata.player.x] = '0';
	gdata->mapdata.maparray[move_y][move_x] = 'P';
	gdata->mapdata.player.x = move_x;
	gdata->mapdata.player.y = move_y;
	gdata->count++;
	ft_putstr("Move Count = ");
	ft_putnbr(gdata->count);
	ft_putstr("\n");
	render_map(gdata, 0, 0);
}

int	win_close_x(t_game *gdata)
{
	if (gdata->img_floor.img)
		mlx_destroy_image(gdata->mlx_ptr, gdata->img_floor.img);
	if (gdata->img_collect.img)
		mlx_destroy_image(gdata->mlx_ptr, gdata->img_collect.img);
	if (gdata->img_player.img)
		mlx_destroy_image(gdata->mlx_ptr, gdata->img_player.img);
	if (gdata->img_wall.img)
		mlx_destroy_image(gdata->mlx_ptr, gdata->img_wall.img);
	if (gdata->img_exit.img)
		mlx_destroy_image(gdata->mlx_ptr, gdata->img_exit.img);
	mlx_destroy_window(gdata->mlx_ptr, gdata->win_ptr);
	free_array(gdata->mapdata.maparray);
	free(gdata->mlx_ptr);
	exit (0);
	return (0);
}

int	key_handler(int keycode, t_game *gdata)
{
	int	check;

	gdata->move.x = gdata->mapdata.player.x;
	gdata->move.y = gdata->mapdata.player.y;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		gdata->move.x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		gdata->move.x++;
	else if (keycode == KEY_W || keycode == KEY_UP)
		gdata->move.y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		gdata->move.y++;
	else if (keycode == KEY_ESC)
		win_close_x(gdata);
	else
		return (0);
	check = validate_move(gdata, gdata->move.x, gdata->move.y);
	if (check == 1 || check == 2 || check == 4)
		move(gdata, gdata->move.x, gdata->move.y);
	if (check == 3)
		win_close_x(gdata);
	return (0);
}
