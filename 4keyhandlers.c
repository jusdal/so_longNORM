/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4keyhandlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:30:17 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 15:55:50 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key.h"

int win_close_x(t_game *gdata) //SEGFAULT
{
    mlx_destroy_image(gdata->mlx_ptr, gdata->img_floor.img);
    mlx_destroy_image(gdata->mlx_ptr, gdata->img_collect.img);
    mlx_destroy_image(gdata->mlx_ptr, gdata->img_player.img);
    mlx_destroy_image(gdata->mlx_ptr, gdata->img_wall.img);
    mlx_destroy_image(gdata->mlx_ptr, gdata->img_exit.img);
    mlx_destroy_window(gdata->mlx_ptr, gdata->win_ptr);
    //mlx_destroy_display(gdata->mlx_ptr);
    free_array(gdata->mapdata.maparray);
    free(gdata->mlx_ptr);
    exit (0);
    return (0);
}

int key_handler(int keycode, t_game *gdata)
{
    int check;

    gdata->move.x = gdata->mapdata.player.x;
    gdata->move.y = gdata->mapdata.player.y;
    if (keycode == KEY_A || keycode == KEY_LEFT)
        gdata->move.x--;
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        gdata->move.x++;
    else if (keycode == KEY_W || keycode == KEY_UP)
        gdata->move.y--;
    else if (keycode == KEY_S|| keycode == KEY_DOWN)
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
