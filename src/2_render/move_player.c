/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:12:08 by lifan             #+#    #+#             */
/*   Updated: 2025/07/08 14:50:26 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_set(t_game *game)
{
	game->move.speed = 0.1;
	game->move.angle_speed = 0.2;
	game->move.cos_angle = cos(game->player->angle);
	game->move.sin_angle = sin(game->player->angle);
	game->move.size_player = game->size_mini_player;
	if (game->player->left_rotate == true)
		game->player->angle += game->move.angle_speed;
	if (game->player->right_rotate == true)
		game->player->angle -= game->move.angle_speed;
}

void	move_new_point(t_game *game)
{
	if (game->player->key_up == true)
	{
		game->move.new_xp = game->player->m_xp - game->move.cos_angle * game->move.speed;
		game->move.new_yp = game->player->m_yp + game->move.sin_angle * game->move.speed;
	}
	if (game->player->key_down == true)
	{
		game->move.new_xp = game->player->m_xp + game->move.cos_angle * game->move.speed;
		game->move.new_yp = game->player->m_yp - game->move.sin_angle * game->move.speed;
	}
	if (game->player->key_left == true)
	{
		game->move.new_xp = game->player->m_xp + game->move.sin_angle * game->move.speed;
		game->move.new_yp = game->player->m_yp + game->move.cos_angle * game->move.speed;
	}
	if (game->player->key_right == true)
	{
		game->move.new_xp = game->player->m_xp - game->move.sin_angle * game->move.speed;
		game->move.new_yp = game->player->m_yp - game->move.cos_angle * game->move.speed;
	}
}

// check x --> only change new_xp with old_yp
// check y --> only change old_xp with new_yp
// si tous les deux peuvent marche, change de new_x et new_yp
void	move_check(t_game *game)
{
	double	old_xp;
	double	old_yp;
	double	new_xp;
	double	new_yp;
	old_xp = game->player->m_xp;
	old_yp = game->player->m_yp;
	new_xp = game->move.new_xp;
	new_yp = game->move.new_yp;
	if (is_wall(game, new_xp, old_yp) == false
		&& is_wall(game, new_xp + game->move.size_player, old_yp) == false
		&& is_wall(game, new_xp, old_yp + game->move.size_player) == false
		&& is_wall(game, new_xp + game->move.size_player
			, old_yp + game->move.size_player) == false)
	{
		game->player->m_xp = new_xp;
	}
	if (is_wall(game, old_xp, new_yp) == false
		&& is_wall(game, old_xp + game->move.size_player, new_yp) == false
		&& is_wall(game, old_xp, new_yp + game->move.size_player) == false
		&& is_wall(game, old_xp + game->move.size_player
			, new_yp + game->move.size_player) == false)
	{
		game->player->m_yp = new_yp;
	}
}

void	move_player(t_game *game)
{
	move_set(game);
	move_new_point(game);
	move_check(game);
}
