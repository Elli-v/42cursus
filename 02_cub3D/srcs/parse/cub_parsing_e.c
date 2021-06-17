/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:11:41 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 15:20:07 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void cub_resolution(char *line, t_ele *ele, t_bundle *bun)
{
	char **temp;

	temp = ft_split(line, ' ');
	if (ele->r)
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Multiple resolution !\n");
	}
	else if (!(temp[0] && temp[1]) || temp[2])
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Invalid resolution format !\n");
	}
	cub_digit(temp);
	bun->r_width = ft_atoi(temp[0]);
	bun->r_height = ft_atoi(temp[1]);
	if (bun->r_width < 200)
		bun->r_width = 200;
	if (bun->r_height < 200)
		bun->r_height = 200;
	cub_free_2fd(temp);
	free(temp);
	ele->r = 1;
	++ele->total;
}

void cub_texture(char *line, t_ele *ele, t_bundle *bun, int element)
{
	char **cub;
	char **temp;
	int *flag;

	cub = cub_b_flag_connect(bun, element);
	flag = cub_e_flag_connect(ele, element);
	temp = ft_split(line, ' ');
	if (*flag)
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Duplicate Texture !\n");
	}
	else if (temp[1] || !temp[0])
	{
		cub_free_2fd(temp);
		cub_error("ERROR : Invalid Texture !\n");
	}
	cub_extention(temp[0], ".xpm", 0);
	*cub = cub_tex_filepath(temp[0]);
	cub_free_2fd(temp);
	free(temp);
	*flag = 1;
	++ele->total;
}

void cub_rgb(char *line, t_ele *ele, t_bundle *bun, int flag)
{
	t_rgb *rgb;
	char **temp;
	int *e_flag;

	rgb = cub_rgb_flag(bun, flag);
	e_flag = cub_ele_flag(ele, flag);
	temp = ft_split(line, ',');
	if (temp == NULL)
		cub_error("error!\n");
	cub_rgb_error(e_flag, temp);
	cub_digit(temp);
	rgb->r = ft_atoi_rgb(temp[0]);
	rgb->g = ft_atoi_rgb(temp[1]);
	rgb->b = ft_atoi_rgb(temp[2]);
	cub_check_rgb(rgb);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	*e_flag = 1;
	++ele->total;
	rgb->color = (rgb->r * 256 * 256) + (rgb->g * 256) + rgb->b;
}

int parsing_e_convert(char *line, t_ele *ele, t_bundle *bun)
{
	if (ft_strlen(line) < 2)
		return (0);
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
	else
		cub_error("ERROR : value of the file is invalid ! \n");
	return (0);
}

int parsing_e(char *line, t_par *par)
{
	int i;

	i = 0;
	while (cub_space(line[i]))
		i++;
	if (ft_isalpha(line[i]))
		parsing_e_convert(line + i, &par->ele, &par->bun);
	else if (ft_isdigit(line[i]))
	{
		par->ele.map_start = 1;
		return (-1);
	}
	return (0);
}
