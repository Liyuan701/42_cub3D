/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:09 by lifan             #+#    #+#             */
/*   Updated: 2025/05/27 11:41:13 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//TODO This page we will control the movement of player
//TODO Left/right trun, others move.

int	ft_key(int keycode, t_game	*game)
{
	if (keycode == KEY_A)
		game->player->forward = -1;
	else if (keycode == KEY_S)
		game->player->forward = -1;
	else if (keycode == KEY_D)
		game->player->forward = +1;
	else if (keycode == KEY_W)
		game->player->forward = +1;
	else if (keycode == RIGHT)
		game->player->turn = +1;
	else if (keycode == LEFT)
		game->player->turn = -1;
	else if (keycode == ESC)
		return (ft_clean(game));
	return (ft_move(keycode, game));
}
