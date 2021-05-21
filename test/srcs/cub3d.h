/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:28:31 by soooh             #+#    #+#             */
/*   Updated: 2021/05/21 18:02:47 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define TITLE "cub3D"

# define INVALID_INPUT_VALUE	100
# define EMPTY_FD	101
# define NO_PLAYER	102
# define INVALID_EXTENTION	103
# define MANY_ELEMENTS	104
# define FEW_ELEMENTS	105
# define INVALID_ELEMENTS	106
# define MULTIPLE_RESOLUTION	107
# define INVALID_RESOLUTION	108
# define DUPLICATE_TEXTURE	109
# define INVALID_TEXTURE	110
# define MISSING_MAP		111
# define MANY_PLAYER		112
# define WALL_NOT_CLOSE		113
# define WRONG_CHAR_IN_MAP	114
# define NEW_LINE_IN_MAP	115
# define DUPLICATE_INFO_F_OR_C	116
# define INACCURATE_RGB_FORMAT	117
# define WRONG_RGB_RANGE	118
# define FAILED_MLX	201
# define FAILED_NEW_WINDOW	202
# define FAILED_ASSIGN_IMAGE	203
# define INVALID_XPM_FILE	204
# define FAILED_SAVE_IMAGE	205

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
	int				r_width;
	int				r_height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	t_rgb			floor;
	t_rgb			ceiling;

}					t_bundle;

#endif
