/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:54:50 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 18:23:05 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			ray_set_drawstart_end(t_game *game)
{
	game->ray.lineheight = (int)(game->bun.r_height / game->ray.pwall_d);
	game->ray.drawstart = (-(game->ray.lineheight) / 2)
		+ (game->bun.r_height / 2);
	if (game->ray.drawstart < 0)
		game->ray.drawstart = 0;
	game->ray.drawend = (game->ray.lineheight / 2) + (game->bun.r_height / 2);
	if (game->ray.drawend >= game->bun.r_height)
		game->ray.drawend = game->bun.r_height;
}

void			ray_draw_tex(t_game *game, int tex_x, int i, int tex_num)
{
	double	tex_pos;
	int		tex_y;
	int		color;
	int		j;

	tex_pos = (game->ray.drawstart - game->bun.r_height / 2
		+ game->ray.lineheight / 2) * game->tex[tex_num].step;
	j = game->ray.drawstart - 1;
	while (++j < game->ray.drawend)
	{
		tex_y = (int)tex_pos & (game->tex[tex_num].tex_h - 1);
		tex_pos += game->tex[tex_num].step;
		color =
			game->tex[tex_num].img.data[game->tex[tex_num].tex_h
			* tex_y + tex_x];
		game->buf[j][i] = color;
	}
}

int				ray_set_tex_num(t_game *game)
{
	if (game->ray.side)
	{
		if (0 < game->ray.raydiry)
			return (T_EAST);
		else
			return (T_WEST);
	}
	else
	{
		if (0 < game->ray.raydirx)
			return (T_SOUTH);
		else
			return (T_NORTH);
	}
}

void			ray_set_tex(t_game *game, int i)
{
	int		tex_num;
	double	wallx;
	int		tex_x;

	tex_num = ray_set_tex_num(game);
	game->tex[tex_num].step = 1.0 * game->tex[tex_num].img.img_height
	/ game->ray.lineheight;
	if (!game->ray.side)
		wallx = game->play.y + game->ray.pwall_d * game->ray.raydiry;
	else
		wallx = game->play.x + game->ray.pwall_d * game->ray.raydirx;
	wallx -= floor(wallx);
	tex_x = (int)(wallx * (double)game->tex[tex_num].tex_w);
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		tex_x = game->tex[tex_num].tex_w - tex_x - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		tex_x = game->tex[tex_num].tex_w - tex_x - 1;
	ray_draw_tex(game, tex_x, i, tex_num);
}
