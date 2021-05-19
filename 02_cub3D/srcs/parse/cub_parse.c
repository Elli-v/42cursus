/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:10:23 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 17:46:11 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				cub_strcmp(const char *str1, const char *str2)
{
	while ((*str1 || *str2))
		if (*str1++ != *str2++)
			return ((unsigned char)*--str1 - (unsigned char)*--str2);
	return (0);
}

void			cub_check_arg(int argc, char *argv[], int *fd)
{
	if (argc != 2 && !(argc == 3 && !cub_strcmp("--save", argv[2])))
		cub_error("ERROR : value entered is not valid ! \n");
	cub_extention(argv[1], ".cub");
	cub_open_check(fd, argv[1], 1);
}

void			cub_open_check(int *fd, char *file, int argv)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		cub_error("ERROR : Invaild file !");
	if (!argv)
		close(*fd);
}

void			cub_open_texture(t_par *par)
{
	int			fd;

	cub_open_check(&fd, par->bun.no, 0);
	cub_open_check(&fd, par->bun.so, 0);
	cub_open_check(&fd, par->bun.we, 0);
	cub_open_check(&fd, par->bun.ea, 0);
	cub_open_check(&fd, par->bun.sp, 0);
}

int				parse(t_par *par, int fd)
{
	char		*line;
	int			element;

	line = ft_strdup("");
	if (!line)
		return (-1);
	cub_einit(&par->ele);
	cub_binit(&par->bun);
	element = 0;
	while (!element && get_next_line(fd, &line) > 0)
		element = parsing_e(line, par);
	cub_ele_total(par, &line, fd);
	cub_map_init(&par->map);
	if (par->ele.map_start)
		parsing_m(line, &par->map);
	while (get_next_line(fd, &line) > 0)
		parsing_m(line, &par->map);
	free(line);
	close(fd);
	cub_map_missing(par);
	cub_open_texture(par);
	cub_map_validity(&par->map);
	return (0);
}
