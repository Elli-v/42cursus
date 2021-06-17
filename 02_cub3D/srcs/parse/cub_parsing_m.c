/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:16:55 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 15:20:09 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int *cub_map_stack2(t_map *mflag, int ***temp, int i, int pre)
{
	int *tennp;
	int j;

	tennp = (int *)ft_calloc(sizeof(int), (mflag->col));
	if (!tennp)
	{
		cub_free_map(*temp, mflag->row);
		return (0);
	}
	j = -1;
	while (++j < pre && j < mflag->col)
		tennp[j] = mflag->map[i][j];
	if (j != mflag->col)
	{
		while (j < mflag->col)
			tennp[j++] = OUT_EMPTY;
	}
	return (tennp);
}

int **cub_map_stack(char *line, t_map *mflag, int pre)
{
	int **temp;
	int i;

	i = -1;
	temp = (int **)malloc(sizeof(int *) * (mflag->row));
	if (!temp)
		return (0);
	while (++i < mflag->row - 1)
		temp[i] = cub_map_stack2(mflag, &temp, i, pre);
	temp[i] = cub_map_convert(line, mflag, pre);
	return (temp);
}

int cub_map_check(char *line, t_map *mflag)
{
	int i;
	int len;
	int pre;

	i = 0;
	len = ft_strlen(line);
	pre = mflag->col;
	while (line[i] && cub_map_element(line[i], mflag))
		i++;
	if (line[i] != '\0')
	{
		cub_free_map(mflag->map, mflag->row);
		cub_error("ERROR : Wrong character in map !\n");
	}
	++mflag->row;
	if (len > mflag->col)
		mflag->col = len;
	return (pre);
}

void parsing_m(char *line, t_map *mflag)
{
	int **temp;
	int pre;

	if (ft_strlen(line) < 2)
	{
		cub_free_map(mflag->map, mflag->row);
		cub_error("ERROR : New line in map !\n");
	}
	pre = cub_map_check(line, mflag);
	temp = cub_map_stack(line, mflag, pre);
	if (mflag->row > 1)
		cub_free_map(mflag->map, mflag->row - 1);
	mflag->map = temp;
}
