/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:25:56 by soooh             #+#    #+#             */
/*   Updated: 2021/05/14 03:05:50 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include <string.h>
# include "../../mlx/mlx.h"
# include "../parse/parse.h"

# define M_SPEED		0.49
# define R_SPEED		0.49
# define PLANE			0.66

enum	ele_tex
{
	T_NORTH,
	T_SOUTH,
	T_EAST,
	T_WEST,
	T_SPRITE,
	T_CEILING,
	T_FLOOR,
	T_TOTAL
};

typedef struct	s_sprite
{
	int			x;
	int			y;
	int			texture;
}				t_sp;

typedef struct	s_sp_bun
{
	int			*order;
	double		*distance;
	double		*zbuffer;
	t_sp		*sp;
}				t_sp_bundle;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_ray_tex
{
	t_img		img;
	double		step;
	int			tex_h;
	int			tex_w;
}				t_ray_tex;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_player;

typedef struct	s_game
{
	int			save;
	int			**buf;
	void		*mlx;
	void		*win;
	int			sizex;
	int			sizey;
	int			**map;
	int			map_row;
	int			map_col;
	int			sp_total;
	int			mouse_x;
	int			mouse_y;
	t_sp_bundle	sp_bun;
	t_img		img;
	t_ray_tex	tex[T_TOTAL];
	t_player	play;
	t_bundle	bun;	
}				t_game;

void			ray_dir_copy(t_par *par, t_game *game);
void			ray_cub_copy(t_par *par, t_game *game, int argc);
void			ray_tex_init(t_game *game);
void			ray_window_init(t_game *game);
void			ray_image_init(t_game *game);

void			ray_sprite_init(t_game *game);
void			ray_sprite(t_game *game);

#endif