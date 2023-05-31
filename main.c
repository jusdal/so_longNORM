/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:22:38 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/31 19:37:48 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mapdata	data;

	check_filetype(argc, argv[1]);
	data.maparray = create_map_array(argv[1], count_rows(argv[1]));
	init_mapdata(&data, argv[1]);
	check_map_all(&data);
	check_path(&data);
	render_all(data);
	return (0);
}
