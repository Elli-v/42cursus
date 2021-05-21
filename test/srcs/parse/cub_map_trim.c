/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:14:39 by soooh             #+#    #+#             */
/*   Updated: 2021/05/14 02:57:07 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				cub_map_out_empty(t_map mflag, int *idx)
{
	int			row;
	int			col;
	int			out_empty;

	col = -1;
	while (++col < mflag.col)
	{
		out_empty = 0;
		row = -1;
		while (++row < mflag.row)
		{
			if (mflag.map[row][col] == OUT_EMPTY)
				out_empty++;
		}
		if (out_empty == mflag.row)
		{
			*idx = col;
			return (1);
		}
	}
	return (0);
}

int				*cub_map_trim2(t_map *mflag, int ***temp, int i, int idx)
{
	int			j;
	int			k;
	int			*mall;

	mall = (int *)malloc(sizeof(int) * (mflag->col - 1));
	if (!mall)
	{
		cub_free_map(*temp, mflag->row);
		return (0);
	}
	j = -1;
	k = -1;
	while (++j < mflag->col)
	{
		if (j == idx && j != mflag->col)
			j++;
		mall[++k] = mflag->map[i][j];
	}
	return (mall);
}

void			cub_map_trim(t_map *mflag, int idx)
{
	int			i;
	int			**temp;

	i = -1;
	temp = (int **)malloc(sizeof(int *) * mflag->row);
	if (!temp)
		return ;
	while (++i < mflag->row)
		temp[i] = cub_map_trim2(mflag, &temp, i, idx);
	cub_free_map(mflag->map, mflag->row);
	--mflag->col;
	mflag->map = temp;
}

void			cub_map_missing(t_par *par)
{
	int			idx;

	idx = 0;
	if (!par->map.row || !par->map.col)
		cub_error("ERROR : Missing map\n");
	while (cub_map_out_empty(par->map, &idx))
		cub_map_trim(&par->map, idx);
}
