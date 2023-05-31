/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:13:15 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 16:01:17 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    validate_move(t_game *gdata, int move_x, int move_y)
{
    char pos;
    pos = gdata->mapdata.maparray[move_y][move_x];
    if (pos == '0')
        return (1);
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
    else if (pos == 'E')
        return (4);
    else
        return (0);
}

void    move(t_game *gdata, int move_x, int move_y)
{
    if (gdata->mapdata.player.x == gdata->mapdata.exit.x && gdata->mapdata.player.y == gdata->mapdata.exit.y)
        gdata->mapdata.maparray[gdata->mapdata.player.y][gdata->mapdata.player.x] = 'E';
    else
        gdata->mapdata.maparray[gdata->mapdata.player.y][gdata->mapdata.player.x] = '0';
    gdata->mapdata.maparray[move_y][move_x] = 'P';
    gdata->mapdata.player.x = move_x;
    gdata->mapdata.player.y = move_y;
    gdata->count++;
    ft_putstr("Move Count = ");
    ft_putnbr(gdata->count);
    ft_putstr("\n");
    render_map(gdata);
}