/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:48:55 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 18:17:34 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			ray_sprite_init(t_game *game)
{
	t_sp		*sprite;
	double		*temp;
	int			*order;

	sprite = (t_sp *)calloc(sizeof(t_sp), game->sp_total);
	if (!sprite)
		return ;
	game->sp_bun.sp = sprite;
	temp = (double *)calloc(sizeof(double), game->bun.r_width);
	if (!temp)
		return ;
	game->sp_bun.zbuffer = temp;
	temp = (double *)calloc(sizeof(double), game->sp_total);
	if (!temp)
		return ;
	game->sp_bun.distance = temp;
	order = (int *)calloc(sizeof(int *), game->sp_total);
	if (!order)
		return ;
	game->sp_bun.order = order;
}

void			ray_sprite(t_game *game)
{
	int			i;
	int			j;
	int			k;

	ray_sprite_init(game);
	k = 0;
	i = -1;
	while (++i < game->map_row)
	{
		j = -1;
		while (++j < game->map_col)
		{
			if (game->map[i][j] == SPRITE)
			{
				game->sp_bun.sp[k].x = i;
				game->sp_bun.sp[k].y = j;
				k++;
			}
		}
	}
}
