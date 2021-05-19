/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:09:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/15 17:15:58 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"

void	ft_free_string(t_game *game)
{
	free(game->bun.no);
	free(game->bun.so);
	free(game->bun.we);
	free(game->bun.ea);
	free(game->bun.sp);
}

void	ft_free_all(t_game *game)
{
	cub_free_map(game->map, game->map_row);
	cub_free_map(game->buf, game->bun.r_height);
	free(game->sp_bun.order);
	free(game->sp_bun.distance);
	free(game->sp_bun.zbuffer);
}

void	ft_init_buf(t_game *game)
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
