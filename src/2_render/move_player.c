/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yy <yy@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:12:08 by lifan             #+#    #+#             */
/*   Updated: 2025/07/02 19:01:22 by yy               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_player_up(t_game *game, double new_x, double new_y)
{
	if (game->player->key_up == true)
	{
		new_x = game->player->xp - game->move.cos_angle * game->move.speed;
		new_y = game->player->yp + game->move.sin_angle * game->move.speed;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, (new_x + game->move.size_player), new_y) == false)
		{
			game->player->xp = new_x ;
			game->player->yp = new_y;
		}
	}
}

void	move_player_down(t_game *game, double new_x, double new_y)
{
	if (game->player->key_down == true)
	{
		new_x = game->player->xp + game->move.cos_angle * game->move.speed;
		new_y = game->player->yp - game->move.sin_angle * game->move.speed;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, new_x + game->move.size_player,
				new_y + game->move.size_player) == false)
		{
			game->player->xp = new_x;
			game->player->yp = new_y;
		}
	}
}

void	move_player_left(t_game *game, double new_x, double new_y)
{
	if (game->player->key_left == true)
	{

		new_x = game->player->xp + game->move.sin_angle * game->move.speed;
		new_y = game->player->yp + game->move.cos_angle * game->move.speed;
		if (is_wall(game, new_x, new_y) == false
			&& is_wall(game, new_x, new_y + game->move.size_player) == false)
		{
			game->player->xp = new_x;
			game->player->yp = new_y;
		}
	}
}

void	move_player_right(t_game *game, double new_x, double new_y)
{
	if (game->player->key_right == true)
	{
		new_x = game->player->xp - game->move.sin_angle * game->move.speed;
		new_y = game->player->yp - game->move.cos_angle * game->move.speed;

		if (is_wall(game, new_x + game->move.size_player, new_y) == false
			&& is_wall(game, new_x + game->move.size_player,
				new_y + game->move.size_player) == false)
		{
			game->player->xp = new_x;
			game->player->yp = new_y;
		}
	}
}

void	move_player(t_game *game, double size_square)
{
	game->move.speed = 0.2;
	game->move.angle_speed = 0.03;
	game->move.cos_angle = cos(game->player->angle);
	game->move.sin_angle = sin(game->player->angle);
	game->move.size_player = game->size_mini_player;
	if (game->player->left_rotate == true)
		game->player->angle += game->move.angle_speed;
	if (game->player->right_rotate == true)
		game->player->angle -= game->move.angle_speed;
	move_player_up(game, game->move.new_x, game->move.new_y);
	move_player_down(game, game->move.new_x, game->move.new_y);
	move_player_left(game, game->move.new_x, game->move.new_y);
	move_player_right(game, game->move.new_x, game->move.new_y);
}
