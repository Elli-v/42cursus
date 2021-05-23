/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_cf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:52:51 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 16:26:41 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			ray_coloring(t_game *game)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game->bun.r_width)
	{
		j = -1;
		while (++j < game->bun.r_height)
		{
			game->buf[j][i] = game->bun.floor.color;
			game->buf[game->bun.r_height - j - 1][i] = game->bun.ceiling.color;
		}
	}
}

void			ray_set_up(t_game *game, int i)
{
	game->ray.camerax = 2 * i / (double)game->bun.r_width - 1;
	game->ray.raydirx = game->play.dirx + game->play.planex * game->ray.camerax;
	game->ray.raydiry = game->play.diry + game->play.planey * game->ray.camerax;
	game->ray.mapx = (int)(game->play.x);
	game->ray.mapy = (int)(game->play.y);
	game->ray.delta_dx = fabs(1 / game->ray.raydirx);
	game->ray.delta_dy = fabs(1 / game->ray.raydiry);
	game->ray.hit = 0;
}

void			ray_set_side_step(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.side_dx = (game->play.x - game->ray.mapx)
			* game->ray.delta_dx;
		game->ray.stepx = -1;
	}
	else
	{
		game->ray.side_dx = ((game->ray.mapx + 1.0) - game->play.x)
			* game->ray.delta_dx;
		game->ray.stepx = 1;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.side_dy = (game->play.y - game->ray.mapy)
			* game->ray.delta_dy;
		game->ray.stepy = -1;
	}
	else
	{
		game->ray.side_dy = ((game->ray.mapy + 1.0) - game->play.y)
			* game->ray.delta_dy;
		game->ray.stepy = 1;
	}
}

void			ray_set_pwalldist(t_game *game)
{
	while (!(game->ray.hit))
	{
		if (game->ray.side_dx < game->ray.side_dy)
		{
			game->ray.side_dx += game->ray.delta_dx;
			game->ray.mapx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dy += game->ray.delta_dy;
			game->ray.mapy += game->ray.stepy;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mapx][game->ray.mapy] == WALL)
			game->ray.hit = 1;
	}
	if (game->ray.side)
		game->ray.pwall_d = (game->ray.mapy - game->play.y
				+ ((1 - game->ray.stepy) / 2)) / game->ray.raydiry;
	else
		game->ray.pwall_d = (game->ray.mapx - game->play.x
				+ ((1 - game->ray.stepx) / 2)) / game->ray.raydirx;
}
