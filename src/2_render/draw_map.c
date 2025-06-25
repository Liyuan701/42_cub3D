/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:41:01 by lifan             #+#    #+#             */
/*   Updated: 2025/06/25 22:51:27 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	is_wall(t_game *game, int x, int y)
{
	x = x / game->map.size_mini;
	y = y / game->map.size_mini;
	if (y < 0 || y >= game->cub->height || x < 0 || x >= game->cub->width)
		return (true);
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
	game->map.size_block = WIDTH / max_dim;
	game->map.size_mini = WIDTH / PROPORTIONAL / max_dim;
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
