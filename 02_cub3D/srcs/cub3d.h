/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:28:31 by soooh             #+#    #+#             */
/*   Updated: 2021/04/27 00:18:52 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define TITLE "cub3D"

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPRITE 4
# define FLOOR 5
# define CEILING 6

typedef struct		s_element
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				s;
}					t_ele;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
}					t_spr;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}					t_rgb;

typedef struct		s_tex
{
	char			*path[5];
	int				tile[5][256 * 256];
	int				floor;
	int				ceiling;
}					t_tex;

typedef struct		s_bundle
{
	t_tex			tex;
	int				r_width;
	int				r_height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	t_rgb			floor;
	t_rgb			ceiling;
	t_ele			ele;

}					t_bundle;

/*
** cub_utils.c
*/

void				cub_putstr(char *s);
void				cub_error(char *text);
void				cub_digit(char **str);
void				cub_free_2fd(char **str);

/*
** cub_utils_texture.c
*/

int					*cub_flag_connect(t_ele *ele, int element);
void				cub_extention(char *temp, char *ext);

/*
** cub_init.c
*/

void				cub_binit(t_bundle *bun);
void				cub_einit(t_ele *ele);

#endif
