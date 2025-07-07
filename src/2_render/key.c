/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:09 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 14:37:33 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//A --> 0
//D --> 2
//W --> 13
//S --> 1
//left --> 123
//right --> 124
//esc --> 53
int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		game->player->key_down = false;
	else if (keycode == KEY_W)
		game->player->key_up = false;
	else if (keycode == KEY_D)
		game->player->key_right = false;
	else if (keycode == KEY_A)
		game->player->key_left = false;
	else if (keycode == LEFT)
		game->player->left_rotate = false;
	else if (keycode == RIGHT)
		game->player->right_rotate = false;
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		game->player->key_down = true;
	else if (keycode == KEY_W)
		game->player->key_up = true;
	else if (keycode == KEY_D)
		game->player->key_right = true;
	else if (keycode == KEY_A)
		game->player->key_left = true;
	else if (keycode == LEFT)
		game->player->left_rotate = true;
	else if (keycode == RIGHT)
		game->player->right_rotate = true;
	else if (keycode == ESC)
	{
		ft_clean(game);
		exit(0);
	}
	return (0);
}
