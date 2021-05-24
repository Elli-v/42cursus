/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:16:04 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 18:21:25 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			ray_sprite_render_buff(t_game *game, int k)
{
	int			texx;
	int			texy;
	int			j;
	int			color;

	texx = (int)(256 * (k - (-game->sp_bun.sp_r.s_width
					/ 2 + game->sp_bun.sp_r.screenx))
	* game->tex[T_SPRITE].tex_w / game->sp_bun.sp_r.s_width) / 256;
	if (game->sp_bun.sp_r.transy > 0 && k > 0 && k < game->bun.r_width
		&& game->sp_bun.sp_r.transy < game->sp_bun.zbuffer[k])
	{
		j = game->sp_bun.sp_r.drawsy - 1;
		while (++j < game->sp_bun.sp_r.drawey)
		{
			texy = ((((j - game->sp_bun.sp_r.mscreen)
							* 256 - game->bun.r_height * 128
			+ game->sp_bun.sp_r.s_height * 128) * game->tex[T_SPRITE].tex_h)
			/ game->sp_bun.sp_r.s_height) / 256;
			color = game->tex[T_SPRITE].img.data[game->tex[T_SPRITE].tex_w
				* texy + texx];
			if ((color & 0x00FFFFFF) != 0)
				game->buf[j][k] = color;
		}
	}
}

void			ray_set_sprite_draw(t_game *game)
{
	game->sp_bun.sp_r.s_height = (int)fabs((game->bun.r_height
				/ game->sp_bun.sp_r.transy));
	game->sp_bun.sp_r.drawsy = -game->sp_bun.sp_r.s_height
		/ 2 + game->bun.r_height
	/ 2 + game->sp_bun.sp_r.mscreen;
	if (game->sp_bun.sp_r.drawsy < 0)
		game->sp_bun.sp_r.drawsy = 0;
	game->sp_bun.sp_r.drawey = game->sp_bun.sp_r.s_height
		/ 2 + game->bun.r_height
	/ 2 + game->sp_bun.sp_r.mscreen;
	if (game->sp_bun.sp_r.drawey >= game->bun.r_height)
		game->sp_bun.sp_r.drawey = game->bun.r_height - 1;
	game->sp_bun.sp_r.s_width = (int)fabs((game->bun.r_height
				/ game->sp_bun.sp_r.transy));
	game->sp_bun.sp_r.drawsx = -game->sp_bun.sp_r.s_width
		/ 2 + game->sp_bun.sp_r.screenx;
	if (game->sp_bun.sp_r.drawsx < 0)
		game->sp_bun.sp_r.drawsx = 0;
	game->sp_bun.sp_r.drawex = game->sp_bun.sp_r.s_width
		/ 2 + game->sp_bun.sp_r.screenx;
	if (game->sp_bun.sp_r.drawex >= game->bun.r_width)
		game->sp_bun.sp_r.drawex = game->bun.r_width - 1;
}

void			ray_set_sprite(t_game *game, int o)
{
	double		sx;
	double		sy;
	double		invd;

	sx = (game->sp_bun.sp[o].x - game->play.x + 0.5);
	sy = (game->sp_bun.sp[o].y - game->play.y + 0.5);
	invd = 1.0 / (game->play.planex * game->play.diry
		- game->play.dirx * game->play.planey);
	game->sp_bun.sp_r.transx = invd * (game->play.diry
			* sx - game->play.dirx * sy);
	game->sp_bun.sp_r.transy = invd * (-game->play.planey
			* sx + game->play.planex * sy);
	game->sp_bun.sp_r.screenx = (int)((game->bun.r_width / 2)
	* (1 + game->sp_bun.sp_r.transx / game->sp_bun.sp_r.transy));
	game->sp_bun.sp_r.mscreen = (int)(game->sp_bun.sp[o].vmove
			/ game->sp_bun.sp_r.transy);
}

void			ray_sort_sp(t_game *game)
{
	int			order;
	double		dist;
	int			i;
	int			j;

	i = -1;
	while (++i < game->sp_total)
	{
		j = -1;
		while (++j < game->sp_total - 1)
		{
			if (game->sp_bun.distance[j] < game->sp_bun.distance[j + 1])
			{
				order = game->sp_bun.order[j];
				game->sp_bun.order[j] = game->sp_bun.order[j + 1];
				game->sp_bun.order[j + 1] = order;
				dist = game->sp_bun.distance[j];
				game->sp_bun.distance[j] = game->sp_bun.distance[j + 1];
				game->sp_bun.distance[j + 1] = dist;
			}
		}
	}
}

void			ray_draw_sp(t_game *game)
{
	int			i;
	int			k;
	int			o;

	i = -1;
	while (++i < game->sp_total)
	{
		game->sp_bun.order[i] = i;
		game->sp_bun.distance[i] = ((game->play.x - game->sp_bun.sp[i].x)
		* (game->play.x - game->sp_bun.sp[i].x)
		+ (game->play.y - game->sp_bun.sp[i].y)
		* (game->play.y - game->sp_bun.sp[i].y));
	}
	ray_sort_sp(game);
	i = -1;
	while (++i < game->sp_total)
	{
		o = game->sp_bun.order[i];
		ray_set_sprite(game, o);
		ray_set_sprite_draw(game);
		k = game->sp_bun.sp_r.drawsx - 1;
		while (++k < game->sp_bun.sp_r.drawex)
			ray_sprite_render_buff(game, k);
	}
}
