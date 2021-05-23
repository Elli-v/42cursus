/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:20 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 22:47:07 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"

void			ray_init_buf(t_game *game)
{
	int			x;
	int			y;

	y = -1;
	while (++y < game->bun.r_height)
	{
		x = -1;
		while (++x < game->bun.r_width)
			game->buf[y][x] = 0;
	}
}

int				main_loop(t_game *game)
{
	ray_loop(game);
	ray_draw_sp(game);
	image_draw(game);
	ray_init_buf(game);
	return (0);
}

void			run_cub3d(t_game *game, int argc)
{
	if (argc == 3)
		cub_capture(game);
	else
	{
		mlx_loop_hook(game->mlx, &main_loop, game);
		mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, game);
		mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 5, &cub_close, game);
		mlx_loop(game->mlx);
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	t_par		par;
	t_game		game;

	cub_check_arg(argc, argv, &fd);
	cub_einit(&par.ele);
	cub_binit(&par.bun);
	fd = parse(&par, fd);
	cub_map_missing(&par);
	cub_open_texture(&par);
	cub_map_validity(&par.map);
	if (fd < 0)
		return (-1);
	ray_cub_copy(&par, &game, argc);
	ray_window_init(&game);
	ray_image_init(&game);
	ray_tex_init(&game);
	ray_load_texture(&game);
	run_cub3d(&game, argc);
	system("leaks executablename");
	return (0);
}

int				cub_close(t_game *game)
{
	cub_free_all(game);
	exit(0);
}
