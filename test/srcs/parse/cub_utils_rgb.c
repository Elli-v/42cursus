/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:14:03 by soooh             #+#    #+#             */
/*   Updated: 2021/05/12 18:00:33 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			cub_rgb_error(int *e_flag, char **temp)
{
	if (*e_flag)
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Duplicate info for F or C !\n");
	}
	else if (!(temp[0] && temp[1] && temp[2]) || temp[3])
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Inaccurate RGB form !\n");
	}
}

void			cub_check_rgb(int a)
{
	if (!(a >= 0 && a <= 255))
		cub_error("ERROR : RGB range is wrong !\n");
}

t_rgb			*cub_rgb_flag(t_bundle *bun, int flag)
{
	if (flag == FLOOR)
		return (&bun->floor);
	else
		return (&bun->ceiling);
}

int				*cub_ele_flag(t_ele *ele, int flag)
{
	if (flag == FLOOR)
		return (&ele->f);
	else
		return (&ele->c);
}

void			cub_free_char(int row, char **temp)
{
	int		i;

	i = -1;
	if (temp)
	{
		while (++i < row)
			free(*temp++);
		*temp = 0;
	}
}
