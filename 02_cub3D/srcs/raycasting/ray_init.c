/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:55:09 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 15:20:17 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
void			ray_dir_copy(t_par *par, t_game *game)
{
	if (par->map.dir == NORTH)
	{
		game->play.dirx = -1;
		game->play.diry = 0;
		game->play.planey = PLANE;
	}
	else if (par->map.dir == SOUTH)
	{
		game->play.dirx = 1;
		game->play.diry = 0;
		game->play.planey = -PLANE;
	}
	else if (par->map.dir == EAST)
	{
		game->play.dirx = 0;
		game->play.diry = 1;
		game->play.planex = PLANE;
	}
	else if (par->map.dir == WEST)
	{
		game->play.dirx = 0;
		game->play.diry = -1;
		game->play.planex = -PLANE;
	}
}

void			ray_cub_copy(t_par *par, t_game *game, int argc)
{
	game->save = argc;
	game->map_col = par->map.col;
	game->map_row = par->map.row;
	game->play.planex = 0;
	game->play.planey = 0;
	game->map = par->map.map;
	game->play.x = par->map.x - 0.5;
	game->play.y = par->map.y - 0.5;
	ray_dir_copy(par, game);
	game->bun = par->bun;
	mlx_get_screen_size(game->mlx, &game->sizex, &game->sizey);
	if (game->bun.r_width > game->sizey)
		game->bun.r_width = game->sizey;
	if (game->bun.r_height > game->sizex)
		game->bun.r_height = game->sizex;
	game->sp_total = par->map.sp_total;
	game->mouse_x = 0;
	game->mouse_y = 0;
	ray_sprite(game);
}

void			ray_tex_init(t_game *game)
{
	int			i;

	i = -1;
	game->buf = (int **)calloc(sizeof(int *), game->bun.r_height);
	if (!game->buf)
		return ;
	while (++i < game->bun.r_height)
	{
		game->buf[i] = (int *)calloc(sizeof(int), game->bun.r_width);
		if (!game->buf[i])
			cub_free_map(game->buf, game->bun.r_height);
	}
	i = -1;
	while (++i < T_TOTAL)
		game->tex[i].img.img = NULL;
}

void			ray_window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		cub_error("ERROR : Failed mlx !\n");
	game->win = mlx_new_window(game->mlx, game->bun.r_width,
			game->bun.r_height, TITLE);
	if (!game->win)
		cub_error("ERROR : Failed new window !\n");
}

void			ray_image_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->bun.r_width,
			game->bun.r_height);
	if (!game->img.img)
		cub_error("ERROR : Failed assign image\n");
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}
