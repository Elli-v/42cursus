/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_validity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:16:08 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 18:27:25 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int				cub_validity_check(int i, int j, t_map *mflag)
{
	const int	dir_x[4] = {-1, 0, 1, 0};
	const int	dir_y[4] = {0, 1, 0, -1};
	int			x;

	if (mflag->cvisited[i][j] == '1' || mflag->cvisited[i][j] == 'x')
		return (1);
	if (mflag->cvisited[i][j] == 0)
		return (0);
	mflag->cvisited[i][j] = 'x';
	x = -1;
	while (++x < 4)
	{
		if ((i + dir_x[x]) < 0 || i + dir_x[x] > mflag->row + 1)
			continue ;
		if (j + dir_y[x] < 0 || j + dir_y[x] > mflag->col + 1)
			continue ;
		if (!cub_validity_check(i + dir_x[x], j + dir_y[x], mflag))
			return (0);
	}
	return (1);
}

char			**cub_map_malloc(t_map *mflag)
{
	char		**cvisited;
	int			i;

	i = -1;
	cvisited = (char **)calloc(sizeof(char *), (mflag->row + 2));
	if (!cvisited)
		return (NULL);
	while (++i < mflag->row + 2)
	{
		cvisited[i] = (char *)calloc(sizeof(char), mflag->col + 2);
		if (!cvisited[i])
		{
			cub_free_char(mflag->row + 2, mflag->cvisited);
			return (NULL);
		}
	}
	return (cvisited);
}

void			cub_map_copy(t_map *mflag)
{
	char		**cvisited;
	int			i;
	int			j;

	cvisited = cub_map_malloc(mflag);
	i = 0;
	while (++i <= mflag->row)
	{
		j = 0;
		while (++j <= mflag->col)
		{
			if (mflag->map[i - 1][j - 1] == 9)
				continue ;
			if (mflag->map[i - 1][j - 1] >= NORTH)
			{
				if (mflag->map[i - 1][j - 1] <= WEST)
				{
					mflag->x = i;
					mflag->y = j;
				}
			}
			cvisited[i][j] = mflag->map[i - 1][j - 1] + '0';
		}
	}
	mflag->cvisited = cvisited;
}

void			cub_map_validity(t_map *mflag)
{
	cub_map_copy(mflag);
	if (!cub_validity_check(mflag->x, mflag->y, mflag))
	{
		cub_free_char(mflag->row + 2, mflag->cvisited);
		cub_error("ERROR : Wall Not Closed ! \n");
	}
	cub_free_char(mflag->row + 2, mflag->cvisited);
}
