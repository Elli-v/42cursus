/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:25:56 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 22:58:10 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include <string.h>
# include "../../mlx/mlx.h"
# include "../parse/parse.h"

/*
** keys
*/
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_MOTION		6
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_L		123
# define KEY_ARROW_R		124

# define M_SPEED		0.2
# define R_SPEED		0.2
# define PLANE			0.66

# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# define BMP_BPP 24
# define IMG_DEPTH 3
# define T_BYTE char

typedef struct	s_bmp
{
	T_BYTE	file_header[FILE_HEADER_SIZE];
	T_BYTE	info_header[INFO_HEADER_SIZE];
}				t_bmp;

enum	e_tex_side
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
	double		vmove;
}				t_sp;

typedef struct	s_sprite_render
{
	double		transx;
	double		transy;
	int			screenx;
	int			mscreen;
	int			s_height;
	int			drawsy;
	int			drawey;
	int			s_width;
	int			drawsx;
	int			drawex;
}				t_sp_r;

typedef struct	s_sp_bun
{
	int			*order;
	double		*distance;
	double		*zbuffer;
	t_sp		*sp;
	t_sp_r		sp_r;
}				t_sp_bundle;

typedef struct	s_raydir
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		side_dx;
	double		side_dy;
	double		delta_dx;
	double		delta_dy;
	double		pwall_d;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_raydir;

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
	t_bmp		bmp;
	t_sp_bundle	sp_bun;
	t_raydir	ray;
	t_img		img;
	t_ray_tex	tex[T_TOTAL];
	t_player	play;
	t_bundle	bun;
}				t_game;

/*
** cub3d.c
*/
void			ray_init_buf(t_game *game);
int				main_loop(t_game *game);
void			run_cub3d(t_game *game, int argc);
int				main(int argc, char **argv);
int				cub_close(t_game *game);

/*
** cub_save.c
*/
void			cub_capture(t_game *game);
void			ray_bmp_init(t_game *game);
int				cub_bmp_write(t_game *game);
void			write_int(T_BYTE *color, unsigned param);
void			cub_write_pixel(int fd, t_game *game);

/*
** cub_key.c
*/
void			key_w_s(int keycode, t_game *game);
void			key_a_d(int keycode, t_game *game);
void			key_l_r(int keycode, t_game *game);
int				key_press(int keycode, t_game *game);

/*
** cub_exit.c
*/
void			cub_free_all(t_game *game);
void			cub_init_buf(t_game *game);

/*
** ray_draw_cf.c
*/
void			ray_coloring(t_game *game);
void			ray_set_up(t_game *game, int i);
void			ray_set_side_step(t_game *game);
void			ray_set_pwalldist(t_game *game);

/*
** ray_draw_sprite.c
*/
void			ray_sprite_render_buff(t_game *game, int k);
void			ray_set_sprite_draw(t_game *game);
void			ray_set_sprite(t_game *game, int o);
void			ray_sort_sp(t_game *game);
void			ray_draw_sp(t_game *game);

/*
** ray_init.c
*/
void			ray_dir_copy(t_par *par, t_game *game);
void			ray_cub_copy(t_par *par, t_game *game, int argc);
void			ray_tex_init(t_game *game);
void			ray_window_init(t_game *game);
void			ray_image_init(t_game *game);

/*
** ray_load_texture.c
*/

void			ray_texture_free(t_game *game);
void			ray_load_image(t_game *game, char *path, t_img *img);
void			ray_load_texture(t_game *game);

/*
** ray_sprite.c
*/
void			ray_sprite_init(t_game *game);
void			ray_sprite(t_game *game);

/*
** ray_tex.c
*/
void			ray_set_drawstart_end(t_game *game);
void			ray_draw_tex(t_game *game, int tex_x, int i, int tex_num);
int				ray_set_tex_num(t_game *game);
void			ray_set_tex(t_game *game, int i);

/*
** raycasting.c
*/
void			image_draw(t_game *game);
void			ray_loop(t_game *game);
#endif
