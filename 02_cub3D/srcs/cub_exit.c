/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:09:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 22:43:09 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"

void	cub_free_all(t_game *game)
{
	cub_free_map(game->map, game->map_row);
	cub_free_map(game->buf, game->bun.r_height);
	free(game->sp_bun.order);
	free(game->sp_bun.distance);
	free(game->sp_bun.zbuffer);
}

void	cub_init_buf(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->bun.r_height)
	{
		x = -1;
		while (++x < game->bun.r_width)
			game->buf[y][x] = 0;
	}
}
