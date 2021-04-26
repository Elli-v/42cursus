/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:20 by soooh             #+#    #+#             */
/*   Updated: 2021/04/27 00:22:04 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void			cub_resolution(char *line, t_bundle *bun)
{
	char		**temp;

	temp = ft_split(line, ' ');
	if (bun->ele.r)
	{
		cub_free_2fd(temp);
		cub_error("값 두 개 ~ \n");
	}
	else if (!(temp[0] && temp[1]) || temp[2])
	{
		cub_free_2fd(temp);
		cub_error("오류2 \n");
	}
	cub_digit(temp);
	bun->r_width = ft_atoi(temp[0]);
	bun->r_height = ft_atoi(temp[1]);
	cub_free_2fd(temp);
	bun->ele.r = 1;
}

void			cub_texture(char *line, t_bundle *bun, int element)
{
	char		**temp;
	int			*flag;

	flag = cub_flag_connect(&bun->ele, element);
	temp = ft_split(line, ' ');
	if (*flag)
	{
		cub_free_2fd(temp);
		cub_error("값 두 개 \n");
	}
	else if (temp[1] || !temp[0])
	{
		cub_free_2fd(temp);
		cub_error("오류2 \n");
	}
	cub_extention(temp[0], ".xpm");
	cub_free_2fd(temp);
	*flag = 1;
	printf("%d \n", flag[0]);
}

int				parse_e_alpha(char *line, t_bundle *bun)
{
	if (ft_strlen(line) < 3)
		return (1);
	else if (line[0] == 'R' && line[1] == ' ')
		cub_resolution(line + 2, bun);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		cub_texture(line + 2, bun, NORTH);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		cub_texture(line + 2, bun, SOUTH);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		cub_texture(line + 2, bun, WEST);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		cub_texture(line + 2, bun, EAST);
	else if (line[0] == 'F' && line[1] == ' ')
	{
		printf("F \n");
		if (bun->ele.f == 1)
			cub_error("값이 두 개");
		else
			bun->ele.f = 1;
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		printf("C \n");
		if (bun->ele.c == 1)
			cub_error("값이 두 개");
		else
			bun->ele.c = 1;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_bundle	bun;

	cub_einit(&bun.ele);
	cub_binit(&bun);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			parse_e_alpha(line, &bun);
	}
	return (0);
}
