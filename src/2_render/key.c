/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yy <yy@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:09 by lifan             #+#    #+#             */
/*   Updated: 2025/06/23 22:58:42 by yy               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//A --> 0
//D --> 2
//W --> 13
//S --> 1
int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == 1)
        game->player->key_down = false;
    else if (keycode == 13)
        game->player->key_up = false;
    else if (keycode == 2)
        game->player->key_right = false;
    else if (keycode == 0)
        game->player->key_left = false;
    // else if (keycode == KEY_Left)
    //     game->player->left_rotate = false;
    // else if (keycode == KEY_Right)
    //     game->player->right_rotate = false;
    return (0);
}

int ft_key_press(int keycode, t_game *game)
{

	if (keycode == 1)
        game->player->key_down = true;
    else if (keycode == 13)
        game->player->key_up = true;
    else if (keycode == 2)
        game->player->key_right = true;
    else if (keycode == 0)
        game->player->key_left = true;
    // else if (keycode == KEY_Left)
    //     game->player->left_rotate = true;
    // else if (keycode == KEY_Right)
    //     game->player->right_rotate = true;
    else if (keycode == ESC)
    {
        ft_clean(game);
        exit(0);
    }
    return (0);
}

