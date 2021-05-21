/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:11:41 by soooh             #+#    #+#             */
/*   Updated: 2021/05/21 20:58:25 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

void			cub_resolution(char *line, t_ele *ele, t_bundle *bun)
{
	char		**temp;

	temp = ft_split(line, ' ');		
	if (ele->r)
		print_ele_error(MULTIPLE_RESOLUTION);
	else if (!(temp[0] && temp[1]) || temp[2])
		print_ele_error(INVALID_RESOLUTION);
	cub_digit(temp);
	cub_resolution_cut(temp, bun);
	cub_free_2fd(temp);
	ele->r = 1;
	++ele->total;
}

void			cub_texture(char *line, t_ele *ele, t_bundle *bun, int element)
{
	char		**cub;
	char		**temp;
	int			*flag;

	cub = cub_b_flag_connect(bun, element);
	flag = cub_e_flag_connect(ele, element);
	temp = ft_split(line, ' ');
	if (*flag)
	{
		cub_free_2fd(temp);
		print_ele_error(DUPLICATE_TEXTURE);
	}
	else if (temp[1] || !temp[0])
	{
		cub_free_2fd(temp);
		print_ele_error(INVALID_TEXTURE);
	}
	cub_extention(temp[0], ".xpm", 0);
	*cub = cub_tex_filepath(temp[0]);
	cub_free_2fd(temp);
	*flag = 1;
	++ele->total;
}

void			cub_rgb(char *line, t_ele *ele, t_bundle *bun, int flag)
{
	t_rgb		*rgb;
	char		**temp;
	int			*e_flag;

	rgb = cub_rgb_flag(bun, flag);
	e_flag = cub_ele_flag(ele, flag);
	temp = ft_split(line, ',');
	cub_rgb_error(e_flag, temp);
	cub_digit(temp);
	rgb->r = ft_atoi(temp[0]);
	cub_check_rgb(rgb->r);
	rgb->g = ft_atoi(temp[1]);
	cub_check_rgb(rgb->g);
	rgb->b = ft_atoi(temp[2]);
	cub_check_rgb(rgb->b);
	cub_free_char(3, temp);
	if (temp)
		free(temp);
	*e_flag = 1;
	++ele->total;
	rgb->color = (rgb->r * 256 * 256) + (rgb->g * 256) + rgb->b;
}

int				parsing_e_convert(char *line, t_ele *ele, t_bundle *bun)
{
	if (ft_strlen(line) < 3)
		return (1);
	else if (line[0] == 'R' && line[1] == ' ')
		cub_resolution(line + 2, ele, bun);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		cub_texture(line + 2, ele, bun, NORTH);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		cub_texture(line + 2, ele, bun, SOUTH);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		cub_texture(line + 2, ele, bun, WEST);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		cub_texture(line + 2, ele, bun, EAST);
	else if (line[0] == 'S' && line[1] == ' ')
		cub_texture(line + 2, ele, bun, SPRITE);
	else if (line[0] == 'F' && line[1] == ' ')
		cub_rgb(line + 2, ele, bun, FLOOR);
	else if (line[0] == 'C' && line[1] == ' ')
		cub_rgb(line + 2, ele, bun, CEILING);
	return (0);
}

int				parsing_e(char *line, t_par *par)
{
	int			i;

	i = 0;
	while (cub_space(line[i]))
		++i;
	if (ft_isalpha(line[i]) && line[0] != ' ')
	{
		if (parsing_e_convert(line + i, &par->ele, &par->bun))
			return (-1);
	}
	else if (ft_isdigit(line[i]))
	{
		par->ele.map_start = 1;
		return (-1);
	}
	else if (i != (int)ft_strlen(line))
		return (-1);
	return (0);
}
