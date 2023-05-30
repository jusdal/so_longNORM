/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:22:38 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/30 21:47:30 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
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
	return (0);

    void *mlx_ptr;
    void *win_ptr;
	void *moon;
	void *astro;
	void *rock;
	void *star;
	int width;
	int height;

	width = 500;
	height = 500;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        error("Malloc Error\n");
	moon = mlx_xpm_file_to_image(mlx_ptr, "img/moon64.xpm", &width, &height);
	astro = mlx_xpm_file_to_image(mlx_ptr, "img/astro64.xpm", &width, &height); 
	rock = mlx_xpm_file_to_image(mlx_ptr, "img/rock64.xpm", &width, &height);
	star = mlx_xpm_file_to_image(mlx_ptr, "img/star32.xpm", &width, &height);  
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "SOOOO LOOOONG!");
    if (!win_ptr)
        error("Malloc Error\n");
	mlx_put_image_to_window(mlx_ptr, win_ptr, moon, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, moon, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, moon, 0, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, astro, 64, 0);	
	mlx_put_image_to_window(mlx_ptr, win_ptr, rock, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, star, 16, 80);


    mlx_loop(mlx_ptr);
    return (0);*/

    t_mapdata	data;

	check_filetype(argc, argv[1]);
	data.maparray = create_map_array(argv[1], count_rows(argv[1]));
	init_mapdata(&data, argv[1]);

	printf("data.width: %d\n", data.width);
	printf("data.height: %d\n", data.height);

	check_map_all(&data);

	printf("data.n_player: %d\n", data.n_player);
	printf("data.n_exit: %d\n", data.n_exit);
	printf("data.n_collect: %d\n", data.n_collect);
	printf("player is at [%d, %d]\n", data.player.x, data.player.y);
	printf("exit is at [%d, %d]\n", data.exit.x, data.exit.y);

	printf("map[0] = %s", data.maparray[0]);
	printf("map[1] = %s", data.maparray[1]);
	printf("map[2] = %s", data.maparray[2]);
	printf("map[3] = %s", data.maparray[3]);
	printf("map[4] = %s", data.maparray[4]);
	printf("map[5] = %s\n", data.maparray[5]);

	check_path(&data);
    render(data);

	free_array(data.maparray);
	return (0);
}