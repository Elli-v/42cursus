/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_load_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:17:35 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 18:21:59 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			ray_texture_free(t_game *game)
{
	free(game->bun.no);
	free(game->bun.so);
	free(game->bun.we);
	free(game->bun.ea);
	free(game->bun.sp);
}

void			ray_load_image(t_game *game, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width,
		&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
		&img->endian);
}

void			ray_load_texture(t_game *game)
{
	int			i;

	ray_load_image(game, game->bun.no, &game->tex[T_NORTH].img);
	ray_load_image(game, game->bun.so, &game->tex[T_SOUTH].img);
	ray_load_image(game, game->bun.ea, &game->tex[T_EAST].img);
	ray_load_image(game, game->bun.we, &game->tex[T_WEST].img);
	ray_load_image(game, game->bun.sp, &game->tex[T_SPRITE].img);
	i = -1;
	while (++i < T_TOTAL)
	{
		game->tex[i].tex_w = game->tex[i].img.img_width;
		game->tex[i].tex_h = game->tex[i].img.img_height;
	}
	ray_texture_free(game);
}
