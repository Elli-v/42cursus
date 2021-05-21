/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 05:48:44 by soooh             #+#    #+#             */
/*   Updated: 2021/05/21 20:22:39 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			print_ele_error(int message)
{
	if (message == INVALID_INPUT_VALUE)
		cub_putstr("ERROR : value entered is not valid ! \n");
	else if (message == EMPTY_FD)
		cub_putstr("ERROR : empty file ! \n");
	else if (message == NO_PLAYER)
		cub_putstr("ERROR : no player ! \n");
	else if (message == INVALID_EXTENTION)
		cub_putstr("ERROR : Wrong file type ! \n");
	else if (message == MANY_ELEMENTS)
		cub_putstr("ERROR : Too many elements info !\n");
	else if (message == FEW_ELEMENTS)
		cub_putstr("ERROR : Missing element info\n");
	else if (message == INVALID_ELEMENTS)
		cub_putstr("ERROR : Element info not valid\n");
	else if (message == MULTIPLE_RESOLUTION)
		cub_putstr("ERROR : Multiple resolution !\n");
	else if (message == INVALID_RESOLUTION)
		cub_putstr("ERROR : Invalid resolution format !\n");
	else if (message == DUPLICATE_TEXTURE)
		cub_putstr("ERROR : Duplicate Texture !");
	else if (message == INVALID_TEXTURE)
		cub_putstr("ERROR : Invalid Texture !\n");
	exit(0);
}

void			cub_resolution_cut(char **temp, t_bundle *bun)
{
	if ((ft_strlen(temp[0])) > 5 || (ft_strlen(temp[1])) > 5)
	{
		if ((ft_strlen(temp[0]) > 5))
			bun->r_width = 9999;
		if ((ft_strlen(temp[1]) > 5))
			bun->r_height = 9999;
	}
	else
	{
		bun->r_width = ft_atoi(temp[0]);
		bun->r_height = ft_atoi(temp[1]);
	}
	if (bun->r_width < 200 || bun->r_height < 200)
	{
		if (bun->r_width < 200)
			bun->r_width = 200;
		else if (bun->r_height < 200)
			bun->r_height = 200;
	}
}