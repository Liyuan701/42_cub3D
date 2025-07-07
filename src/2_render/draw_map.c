/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:41:01 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 13:48:20 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	is_wall(t_game *game, int x, int y)
{
	printf("is_wall called with x=%d, y=%d\n", x, y);//! debug
	x = x / game->size_mini;
	y = y / game->size_mini;
	if (y < 0 || y >= game->cub->height || x < 0 || x >= game->cub->width)
		ft_error_close(game, "map index out");
	if (game->cub->copy[y][x] == '0')
		return (false);
	return (true);
}

//* use max_dim to know wether WIDTH > HEIGHT OR HEIGHT > WIDTH
//* window use the HEIGHT cause we want the wall height.
//* mini only use the width
void	set_map_size(t_game *game)
{
	int	max_dim;

	if (game->cub->width <= 0 || game->cub->height <= 0)
		printf("width:%d, height: %d\n", game->cub->width, game->cub->height);
	if (game->cub->width > game->cub->height)
		max_dim = game->cub->width;
	else
		max_dim = game->cub->height;
	if (WIDTH / game->cub->width < 64)
		game->size_block = WIDTH / game->cub->width;
	else
		game->size_block = 64;
	game->size_mini = WIDTH / PROPORTIONAL / max_dim;
	game->size_mini_player = game->size_mini / 1.5;
	game->player->xp = game->player->x * game->size_mini;
	game->player->yp = game->player->y * game->size_mini;
}

//copy map --> 0 or 1 or V
void	draw_map(t_game *game, int size_mini, int color_c, int color_f)
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
			p.x = x * size_mini;
			p.y = y * size_mini;
			if (game->cub->copy[y][x] == '0')
			{
				draw_square(&p, size_mini, color_f);
			}
			else
				draw_square(&p, size_mini, color_c);
			x++;
		}
		y++;
	}
}
