/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yy <yy@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:42 by lifan             #+#    #+#             */
/*   Updated: 2025/07/02 19:20:45 by yy               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_player(t_game *game, int size, int color)
{
	t_pixel	p;

	p.game = game;
	p.x = game->player->xp;
	p.y = game->player->yp;
	draw_square(&p, size, color);
	int cx = p.x + size/2;
    int cy = p.y;
    int ex = cx - cos(game->player->angle) * size;
    int ey = cy + sin(game->player->angle) * size;
    init_line(game, cx, cy, ex, ey);
}

void init_line(t_game *game, int x0, int y0, int x1, int y1)
{
	game->br.distance_x = abs(x1 - x0);
	game->br.distance_y = -abs(y1 - y0);
	game->br.error = game->br.distance_x + game->br.distance_y;

	if (x0 < x1)
		game->br.dir_x = 1;
	else
		game->br.dir_x = -1;
	
	if (y0 < y1)
		game->br.dir_y = 1;
	else
		game->br.dir_y = -1;
	
	while(1)
	{
		put_pixel(game, x0, y0, 0xF08080);
		if (x0 == x1 && y0 == y1)
			break;
		game->br.error2 = 2 * game->br.error;
		if (game->br.error2 >= game->br.distance_y)
		{
			game->br.error += game->br.distance_y;
			x0 += game->br.dir_x;
		}
		if (game->br.error2 <= game->br.distance_x)
		{
			game->br.error += game->br.distance_x;
			y0 += game->br.dir_y;
		}
	}
}

