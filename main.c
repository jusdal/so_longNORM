/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:22:38 by jdaly             #+#    #+#             */
/*   Updated: 2023/06/01 18:18:00 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	data;

	check_filetype(argc, argv[1]);
	data.mapdata.maparray = create_map_array(argv[1], count_rows(argv[1]));
	init_mapdata(&data.mapdata, argv[1]);
	check_map_all(&data.mapdata);
	check_path(&data.mapdata);
	render_all(&data);
	return (0);
}
