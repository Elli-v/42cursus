/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:20 by soooh             #+#    #+#             */
/*   Updated: 2021/05/14 03:05:31 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	int			fd;
	t_par		par;
	t_game		game;

	cub_check_arg(argc, argv, &fd);
	fd = parse(&par, fd);
	if (fd < 0)
		return (-1);
	ray_cub_copy(&par, &game, argc);
	ray_window_init(&game);
	ray_image_init(&game);
	ray_tex_init(&game);
	return (0);
}
