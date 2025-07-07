/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:42 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 14:48:39 by lifan            ###   ########.fr       */
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
	game->br.x0 = p.x + size / 2;
	game->br.y0 = p.y + size / 2;
	game->ray.pl_x= game->br.x0;
	game->ray.pl_y = game->br.y0;
	game->br.x1 = game->br.x0 - cos(game->player->angle) * size;
	game->br.y1 = game->br.y0 + sin(game->player->angle) * size;
	init_draw_line(game);
	draw_line(game, 0xF08080);
}

void	init_draw_line(t_game *game)
{
	game->br.distance_x = abs(game->br.x1 - game->br.x0);
	game->br.distance_y = -abs(game->br.y1 - game->br.y0);
	game->br.error = game->br.distance_x + game->br.distance_y;
	if (game->br.x0 < game->br.x1)
		game->br.dir_x = 1;
	else
		game->br.dir_x = -1;
	if (game->br.y0 < game->br.y1)
		game->br.dir_y = 1;
	else
		game->br.dir_y = -1;
}

void	draw_line(t_game *game, unsigned int color)
{
	while (1)
	{
		put_pixel(game, game->br.x0, game->br.y0, color);
		if (game->br.x0 == game->br.x1 && game->br.y0 == game->br.y1)
			break ;
		game->br.error2 = 2 * game->br.error;
		if (game->br.error2 >= game->br.distance_y)
		{
			game->br.error += game->br.distance_y;
			game->br.x0 += game->br.dir_x;
		}
		if (game->br.error2 <= game->br.distance_x)
		{
			game->br.error += game->br.distance_x;
			game->br.y0 += game->br.dir_y;
		}
	}
}
