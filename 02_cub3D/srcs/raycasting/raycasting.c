/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:54:52 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 18:25:03 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			image_draw(t_game *game)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game->bun.r_height)
	{
		j = -1;
		while (++j < game->bun.r_width)
			game->img.data[(int)(i) * game->bun.r_width + (int)(j)] =
			game->buf[i][j];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void			ray_loop(t_game *game)
{
	int			i;

	ray_coloring(game);
	i = -1;
	while (++i < game->bun.r_width)
	{
		ray_set_up(game, i);
		ray_set_side_step(game);
		ray_set_pwalldist(game);
		ray_set_drawstart_end(game);
		ray_set_tex(game, i);
		game->sp_bun.zbuffer[i] = game->ray.pwall_d;
	}
}
