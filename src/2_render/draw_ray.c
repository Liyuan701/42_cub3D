/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:56 by lifan             #+#    #+#             */
/*   Updated: 2025/06/25 22:54:12 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//!DEBUG function
void	ft_draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = (x0 < x1) ? 1 : -1;
	int	sy = (y0 < y1) ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
		put_pixel(game, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

//! DEBUG function 
void	ft_draw_ray_line(t_game *game)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = (int)game->player->x;
	start_y = (int)game->player->y;
	if (game->ray.hit_side == 0)
		end_x = game->ray.map_x * game->size_mini;
	else
		end_x = (int)(game->ray.ray_x \
			+ (game->ray.side_x - game->ray.d_x) * game->ray.vector_x);
	if (game->ray.hit_side == 1)
		end_y = game->ray.map_y * game->size_mini;
	else
		end_y = (int)(game->ray.ray_y \
			+ (game->ray.side_y - game->ray.d_y) * game->ray.vector_y);
	ft_draw_line(game, start_x, start_y, end_x, end_y, RAY);
}

//* from the player, draw ray.
//* angle = direction, use radians.
//* DDA algotithme, by block.
int	ft_ray(t_game *game, t_player *player, double dir, int column)
{
	double	distance;
	char	wall;

	ft_init_ray(game, dir);
	if (!ft_if_encounter(game))
		ft_error_close(game, "Wired, the ray didn't reach the wall.");
	//*ft_draw_ray_line(game);
	distance = ft_cali_fisheye(game, player);
	wall = ft_hit_wall(&game->ray);
	ft_cast_wall(game, distance, column, wall);
}
