/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:28:31 by soooh             #+#    #+#             */
/*   Updated: 2021/05/13 18:41:57 by soooh            ###   ########.fr       */
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
