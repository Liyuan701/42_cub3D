/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yy <yy@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:09 by lifan             #+#    #+#             */
/*   Updated: 2025/06/14 18:35:12 by yy               ###   ########.fr       */
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
		return(0);
	return(-1);
	// 	return (ft_clean(game));
	// return (ft_move(keycode, game));
}
