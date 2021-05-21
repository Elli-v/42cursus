/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:17:15 by soooh             #+#    #+#             */
/*   Updated: 2021/05/21 19:50:17 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char			**cub_b_flag_connect(t_bundle *bun, int element)
{
	if (element == NORTH)
		return (&bun->no);
	else if (element == SOUTH)
		return (&bun->so);
	else if (element == WEST)
		return (&bun->we);
	else if (element == EAST)
		return (&bun->ea);
	else
		return (&bun->sp);
}

int				*cub_e_flag_connect(t_ele *ele, int element)
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

char			*cub_tex_filepath(const char *str)
{
	char		*temp;
	int			i;
	int			len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\r')
		len++;
	temp = (char *)calloc(sizeof(char), (len + 1));
	if (!temp)
		return (0);
	i = -1;
	while (++i < len)
		temp[i] = str[i];
	return (temp);
}

void			cub_extention(char *temp, char *ext, int cub)
{
	char		*str;
	int			i;

	str = ft_strrchr(temp, '.');
	if (!str)
		print_ele_error(INVALID_EXTENTION);
	i = ft_strncmp(str, ext, ft_strlen(ext));
	if (i)
	{
		if (cub)
			print_ele_error(INVALID_EXTENTION);
		else
		{
			free(temp);
			print_ele_error(INVALID_EXTENTION);
		}
	}
}

void			cub_ele_total(t_par *par, char **line, int fd)
{
	if (par->ele.total > TOTAL_E)
	{
		free(*line);
		close(fd);
		print_ele_error(MANY_ELEMENTS);
	}
	if (par->ele.total < TOTAL_E)
	{
		if (par->ele.map_start)
			print_ele_error(FEW_ELEMENTS);
		print_ele_error(INVALID_ELEMENTS);
	}
}
