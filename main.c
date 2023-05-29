/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:22:38 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/29 11:56:40 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()//int argc, char *argv[])
{
	/*char		**maparray;
	t_mapdata	data;

	check_filetype(argc, argv[1]);
	maparray = create_map_array(argv[1], count_rows(argv[1]));
	init_mapdata(&data, maparray, argv[1]);

	printf("data.width: %d\n", data.width);
	printf("data.height: %d\n", data.height);

	check_map_all(maparray, &data);

	printf("data.n_player: %d\n", data.n_player);
	printf("data.n_exit: %d\n", data.n_exit);
	printf("data.n_collect: %d\n", data.n_collect);
	printf("player is at [%d, %d]\n", data.player.x, data.player.y);
	printf("exit is at [%d, %d]\n", data.exit.x, data.exit.y);

	printf("map[0] = %s", maparray[0]);
	printf("map[1] = %s", maparray[1]);
	printf("map[2] = %s", maparray[2]);
	printf("map[3] = %s", maparray[3]);
	printf("map[4] = %s", maparray[4]);
	printf("map[5] = %s\n", maparray[5]);

	check_path(maparray, &data);
	free_array(maparray);
	return (0);*/

    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        error("Malloc Error\n");
    win_ptr = mlx_new_window(mlx_ptr, 300, 300, "SOOOO LOOOONG!");
    if (!win_ptr)
        error("Malloc Error\n");
    mlx_loop(mlx_ptr);
    return (0);
    
}