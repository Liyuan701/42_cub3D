/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:42 by lifan             #+#    #+#             */
/*   Updated: 2025/06/26 00:14:00 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_player(t_game *game, int size, int color)
{
	t_pixel	p;

	p.game = game;
	p.x = game->player->x;
	p.y = game->player->y;
	draw_square(&p, size, color);
}

//! si nous avons encore besoin de set_player ?
//! game->player->dir = c; on a deja l'angle dans player.
//! on a deja le x, y dans player.
void	set_player_start_pos(t_game *game)
{
	int		x;
	int		y;
	bool	player_set;

	y = 0;
	player_set = false;
	while (game->cub->copy[y] && player_set == false)
	{
		x = 0;
		while (game->cub->copy[y][x] && player_set == false)
		{
			if (game->cub->copy[y][x] == '0')//--> changer au strchr "NSEO"
			{
				game->player->x = x * game->size_square;
				game->player->y = y * game->size_square;
				player_set = true;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, t_player *player)
{
	// double move_speed = 1.0;
	double	cos_angle = cos(player->angle);
	double	sin_angle = sin(player->angle);
	double	new_x;
	double	new_y;
	int		wall_y;
	int		wall_x;

	// if (player->left_rotate)
	//     player->angle -= rotate_speed;
	// if (player->right_rotate)
	//     player->angle += rotate_speed;
	if (player->key_up == true)
	{
		new_x = player->x - cos_angle;
		new_y = player->y - sin_angle;
		if (is_wall(game, new_x, new_y) == false)
		{
			player->x = new_x;
			player->y = new_y;
		}
		else
		{
			wall_y = new_y / game->map.size_mini;
			player->y = (wall_y + 1) * game->map.size_mini;
		}
	}
	if (player->key_down == true)
	{
		new_x = player->x + cos_angle;
		new_y = player->y + sin_angle;
		if (is_wall(game, new_x, new_y + game->map.size_mini) == false)
		{
			player->x = new_x;
			player->y = new_y;
		}
		else
		{
			wall_y = (new_y + game->map.size_mini) / game->map.size_mini;
			player->y = (wall_y - 1) * game->map.size_mini;
		}
	}
	if (player->key_left == true)
	{
		new_x = player->x - sin_angle;
		new_y = player->y + cos_angle;
		if (is_wall(game, new_x, new_y) == false)
		{
			player->x = new_x;
			player->y = new_y;
		}
		else
		{
			wall_x = new_x / game->map.size_mini;
			player->x = (wall_x + 1) * game->map.size_mini;
		}
	}
	if (player->key_right == true)
	{
		new_x = player->x + sin_angle;
		new_y = player->y - cos_angle ;
		if (is_wall(game, new_x + game->map.size_mini, new_y) == false)
		{
			player->x = new_x;
			player->y = new_y;
		}
		else
		{
			wall_x = (new_x + game->map.size_mini) / game->map.size_mini;
			player->x = (wall_x - 1) * game->map.size_mini;
		}
	}
}
