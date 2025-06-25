/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:41:01 by lifan             #+#    #+#             */
/*   Updated: 2025/06/25 14:42:19 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	is_wall(t_game *game, int x, int y)
{
	x = x / game->map.size_square;
	y = y / game->map.size_square;
	if (y < 0 || y >= game->cub->height || x < 0 || x >= game->cub->width)
		return (true);
	if (game->cub->copy[y][x] == '0')
		return (false);
	return (true);
}

void	set_map_size(t_game *game)
{
	if (game->cub->width <= 0 || game->cub->height <= 0)
		printf("width:%d, height: %d\n", game->cub->width, game->cub->height);
	if (game->cub->width > game->cub->height)
	{
		game->map.size_square = WIDTH / game->cub->width;
		game->map.size_square_mini = WIDTH / PROPORTIONAL / game->cub->width;
	}
	else
	{
		game->map.size_square = HEIGHT / game->cub->height;
		game->map.size_square_mini = HEIGHT / PROPORTIONAL / game->cub->height;
	}
}

//copy map --> 0 or 1 or V
void	draw_map(t_game *game, int size_square, int color_c, int color_f)
{
	t_pixel	p;
	int		x;
	int		y;

	p.game = game;
	y = 0;
	while (game->cub->copy[y])
	{
		x = 0;
		while (game->cub->copy[y][x])
		{
			p.x = x * size_square;
			p.y = y * size_square;
			if (game->cub->copy[y][x] == '0')
			{
				draw_square(&p, size_square, color_f);
			}
			else
				draw_square(&p, size_square, color_c);
			x++;
		}
		y++;
	}
}
