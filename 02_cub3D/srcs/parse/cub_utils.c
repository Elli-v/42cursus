/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:30:37 by soooh             #+#    #+#             */
/*   Updated: 2021/06/09 15:51:46 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void cub_putstr(char *s)
{
	int i;

	if (s == NULL)
		return (void)(NULL);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void cub_error(char *text)
{
	cub_putstr(text);
	exit(0);
}

int cub_space(char i)
{
	return (i == ' ' || (9 <= i && i <= 13));
}

void cub_digit(char **str)
{
	int i;
	int j;

	j = -1;
	while (str[++j])
	{
		i = 0;
		while (cub_space(str[j][i]))
			i++;
		while (ft_isdigit(str[j][i]))
			i++;
		while (cub_space(str[j][i]))
			i++;
		if (str[j][i] != 0)
		{
			if (str)
			{
				while (*str)
					free(*str++);
				*str = 0;
			}
			cub_error("ERROR : Number decription(s) not valid\n");
		}
	}
}

void cub_free_2fd(char **str)
{
	if (str)
	{
		while (*str)
			free(*str++);
		*str = 0;
	}
}
