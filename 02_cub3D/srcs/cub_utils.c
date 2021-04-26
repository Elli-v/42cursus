/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:30:37 by soooh             #+#    #+#             */
/*   Updated: 2021/04/27 00:21:21 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_putstr(char *s)
{
	int			i;

	if (s == NULL)
		return (void)(NULL);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void			cub_error(char *text)
{
	cub_putstr(text);
	exit(0);
}

void			cub_digit(char **str)
{
	int			i;
	int			j;

	j = -1;
	while (str[++j])
	{
		i = 0;
		while (ft_isdigit(str[j][i]))
		{
			++i;
		}
		if (str[j][i] != 0 && str[j][i] != 13)
		{
			if (str)
			{
				while (*str)
					free(*str++);
				*str = 0;
			}
			cub_error("대충 에러라는 뜻");
		}
	}
}

void			cub_free_2fd(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
