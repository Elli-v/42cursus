/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_convert_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:11:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/19 17:52:56 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				cub_map_convert_dir(t_map *mflag, int dir)
{
	if (dir == NORTH)
		mflag->dir += NORTH;
	else if (dir == SOUTH)
		mflag->dir += SOUTH;
	else if (dir == EAST)
		mflag->dir += EAST;
	else if (dir == WEST)
		mflag->dir += WEST;
	return (dir);
}

int				cub_map_convert_alpha(char line, t_map *mflag)
{
	if (line == 'N')
		return (cub_map_convert_dir(mflag, NORTH));
	else if (line == 'S')
		return (cub_map_convert_dir(mflag, SOUTH));
	else if (line == 'E')
		return (cub_map_convert_dir(mflag, EAST));
	else if (line == 'W')
		return (cub_map_convert_dir(mflag, WEST));
	else
		return (OUT_EMPTY);
}

int				*cub_map_convert(char *line, t_map *mflag, int len)
{
	int			i;
	int			*map_line;

	i = -1;
	len = ft_strlen(line);
	map_line = (int *)calloc(sizeof(int), mflag->col);
	if (!map_line)
		return (0);
	while (++i < mflag->col)
	{
		if (i < len && ft_isdigit(line[i]))
		{
			map_line[i] = line[i] - '0';
			if (map_line[i] == SPRITE)
				mflag->sp_total++;
		}
		else if (i < len && ft_isalpha(line[i]))
			map_line[i] = cub_map_convert_alpha(line[i], mflag);
		else
			map_line[i] = OUT_EMPTY;
	}
	return (map_line);
}
