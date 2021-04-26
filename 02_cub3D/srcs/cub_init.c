/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:32:20 by soooh             #+#    #+#             */
/*   Updated: 2021/04/25 19:35:34 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_binit(t_bundle *bun)
{
	bun->r_width = 0;
	bun->r_height = 0;
	bun->so = 0;
	bun->we = 0;
	bun->ea = 0;
	bun->floor.r = 0;
	bun->floor.g = 0;
	bun->floor.b = 0;
	bun->floor.color = 0;
	bun->ceiling.r = 0;
	bun->ceiling.g = 0;
	bun->ceiling.b = 0;
	bun->ceiling.color = 0;
	bun->sp = 0;
}

void			cub_einit(t_ele *ele)
{
	ele->r = 0;
	ele->no = 0;
	ele->so = 0;
	ele->we = 0;
	ele->ea = 0;
	ele->f = 0;
	ele->c = 0;
	ele->s = 0;
}
