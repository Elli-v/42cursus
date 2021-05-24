/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:05:25 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 22:43:21 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./raycasting/raycasting.h"

void	key_w_s(int keycode, t_game *game)
{
	double	a;
	double	b;

	a = game->play.dirx * M_SPEED * 3;
	b = game->play.diry * M_SPEED * 3;
	if (keycode == KEY_W)
	{
		if (game->map[(int)(game->play.x + a)][(int)game->play.y] != WALL)
			(game->play.x) += (game->play.dirx) * M_SPEED;
		if (game->map[(int)(game->play.x)][(int)(game->play.y + b)] != WALL)
			(game->play.y) += (game->play.diry) * M_SPEED;
	}
	if (keycode == KEY_S)
	{
		if (game->map[(int)(game->play.x - a)][(int)game->play.y] != WALL)
			(game->play.x) -= (game->play.dirx) * M_SPEED;
		if (game->map[(int)(game->play.x)][(int)(game->play.y - b)] != WALL)
			(game->play.y) -= (game->play.diry) * M_SPEED;
	}
}

void	key_a_d(int keycode, t_game *game)
{
	double	a;
	double	b;

	a = game->play.dirx * M_SPEED;
	b = game->play.diry * M_SPEED;
	if (keycode == KEY_D)
	{
		if (game->map[(int)(game->play.x + b)][(int)game->play.y] != WALL)
			(game->play.x) += (game->play.diry) * M_SPEED;
		if (game->map[(int)(game->play.x)][(int)(game->play.y - a)] != WALL)
			(game->play.y) -= (game->play.dirx) * M_SPEED;
	}
	if (keycode == KEY_A)
	{
		if (game->map[(int)(game->play.x - b)][(int)game->play.y] != WALL)
			(game->play.x) -= (game->play.diry) * M_SPEED;
		if (game->map[(int)(game->play.x)][(int)(game->play.y + a)] != WALL)
			(game->play.y) += (game->play.dirx) * M_SPEED;
	}
}

void	key_l_r(int keycode, t_game *game)
{
	double	olddirx;
	double	oldpx;
	double	r;

	olddirx = (game->play.dirx);
	oldpx = (game->play.planex);
	r = R_SPEED;
	if (keycode == KEY_ARROW_R)
	{
		(game->play.dirx) = game->play.dirx * cos(-r)
			- (game->play.diry) * sin(-r);
		(game->play.diry) = olddirx * sin(-r) + (game->play.diry) * cos(-r);
		(game->play.planex) = game->play.planex * cos(-r)
		- (game->play.planey) * sin(-r);
		(game->play.planey) = oldpx * sin(-r) + (game->play.planey) * cos(-r);
	}
	if (keycode == KEY_ARROW_L)
	{
		(game->play.dirx) = game->play.dirx * cos(r)
			- (game->play.diry) * sin(r);
		(game->play.diry) = olddirx * sin(r) + (game->play.diry) * cos(r);
		(game->play.planex) = game->play.planex * cos(r)
		- (game->play.planey) * sin(r);
		(game->play.planey) = oldpx * sin(r) + (game->play.planey) * cos(r);
	}
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cub_free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(keycode, game);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(keycode, game);
	else if (keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		key_l_r(keycode, game);
	return (0);
}
