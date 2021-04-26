/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:17:15 by soooh             #+#    #+#             */
/*   Updated: 2021/04/27 00:22:42 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int				*cub_flag_connect(t_ele *ele, int element)
{
	if (element == NORTH)
		return (&ele->no);
	else if (element == SOUTH)
		return (&ele->so);
	else if (element == WEST)
		return (&ele->we);
	else if (element == EAST)
		return (&ele->ea);
	else
		return (&ele->s);
}

void			cub_extention(char *temp, char *ext)
{
	char		*str;
	int			i;

	str = ft_strrchr(temp, '.');
	if (!str)
		cub_error("확장자 오류쉐이 \n");
	i = ft_strncmp(str, ext, ft_strlen(ext));
	if (i != 0)
	{
		free(temp);
		cub_error("오류쉐이 \n");
	}
}
