/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:42 by lifan             #+#    #+#             */
/*   Updated: 2025/06/27 16:48:20 by yren             ###   ########.fr       */
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

void	draw_player_mini(t_game *game, int size, int color)
{
	t_pixel	p;

	p.game = game;
	p.x = game->player->x / game->size_block * game->size_mini;
	p.y = game->player->y / game->size_block * game->size_mini;
	draw_square(&p, size, color);
}

void	set_player_start_pos(t_game *game)
{
	if (game->player->x < 0 || game->player->y < 0)
		ft_error_close(game, "Invalid player start position.");
	game->player->x = game->player->x * game->size_block;
	game->player->y = game->player->y * game->size_block;
}
