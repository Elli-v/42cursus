/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:08:22 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 17:36:41 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "stdio.h"

void			cub_free_map(int **map, int row)
{
	int			i;
	int			***p;

	i = -1;
	p = &map;
	if (row)
	{
		while (++i < row)
		{
			if ((*p)[i])
				free((*p)[i]);
		}
		free((*p));
	}
}

int				cub_blank(char *line)
{
	int			i;

	i = 0;
	while (cub_space(line[i]))
		i++;
	if (line[i])
		return (1);
	return (0);
}

int				cub_map_element(char e, t_map *mflag)
{
	if (e == 'N' || e == 'S' || e == 'E' || e == 'W')
		mflag->map_dir++;
	if (mflag->map_dir > 1)
	{
		cub_free_map(mflag->map, mflag->row - 1);
		cub_error("ERROR : There should be one player !\n");
		return (0);
	}
	return (e == '0' || e == '1' || e == '2' || e == 'N' || e == 'S'
		|| e == 'E' || e == 'W' || cub_space(e));
}
