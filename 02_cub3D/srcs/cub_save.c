/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:53:44 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 22:58:26 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"

void			cub_capture(t_game *game)
{
	ray_loop(game);
	ray_draw_sp(game);
	image_draw(game);
	ray_bmp_init(game);
	if (!cub_bmp_write(game))
	{
		mlx_destroy_image(game->mlx, game->img.img);
		cub_init_buf(game);
		cub_error("Failed to save image\n");
	}
	mlx_destroy_image(game->mlx, game->img.img);
	cub_init_buf(game);
}

void			ray_bmp_init(t_game *game)
{
	int			file_size;
	int			h_size;

	h_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
	file_size = (h_size) + (game->bun.r_width * game->bun.r_height * IMG_DEPTH);
	ft_bzero(game->bmp.file_header, FILE_HEADER_SIZE);
	ft_bzero(game->bmp.info_header, INFO_HEADER_SIZE);
	game->bmp.file_header[0] = (unsigned char)'B';
	game->bmp.file_header[1] = (unsigned char)'M';
	game->bmp.file_header[2] = (unsigned char)(file_size);
	game->bmp.file_header[3] = (unsigned char)(file_size >> 8);
	game->bmp.file_header[4] = (unsigned char)(file_size >> 16);
	game->bmp.file_header[5] = (unsigned char)(file_size >> 24);
	game->bmp.file_header[10] = (unsigned char)(h_size);
	game->bmp.info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	game->bmp.info_header[4] = (unsigned char)(game->bun.r_width);
	game->bmp.info_header[5] = (unsigned char)(game->bun.r_width >> 8);
	game->bmp.info_header[6] = (unsigned char)(game->bun.r_width >> 16);
	game->bmp.info_header[7] = (unsigned char)(game->bun.r_width >> 24);
	game->bmp.info_header[8] = (unsigned char)(game->bun.r_height);
	game->bmp.info_header[9] = (unsigned char)(game->bun.r_height >> 8);
	game->bmp.info_header[10] = (unsigned char)(game->bun.r_height >> 16);
	game->bmp.info_header[11] = (unsigned char)(game->bun.r_height >> 24);
	game->bmp.info_header[12] = (unsigned char)1;
	game->bmp.info_header[14] = (unsigned char)(BMP_BPP);
}

int				cub_bmp_write(t_game *game)
{
	int			fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (fd < 0)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		cub_error("Failed to save image\n");
	}
	write(fd, game->bmp.file_header, FILE_HEADER_SIZE);
	write(fd, game->bmp.info_header, INFO_HEADER_SIZE);
	cub_write_pixel(fd, game);
	close(fd);
	return (1);
}

void			write_int(T_BYTE *color, unsigned param)
{
	color[0] = (param >> 0);
	color[1] = (param >> 8);
	color[2] = (param >> 16);
}

void			cub_write_pixel(int fd, t_game *game)
{
	int			i;
	int			j;
	T_BYTE		color[3];
	T_BYTE		padding[3];
	int			padding_size;

	ft_bzero(padding, 3);
	padding_size = (4 - (game->bun.r_width * IMG_DEPTH) % 4) % 4;
	i = game->bun.r_height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < game->bun.r_width)
		{
			write_int(color, game->img.data[(i * game->bun.r_width + j)]);
			write(fd, color, 3);
		}
		write(fd, padding, padding_size);
	}
}
