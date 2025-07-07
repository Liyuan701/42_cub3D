/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:56 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 17:47:27 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* draw the line from (x0, y0) to (x1, y1)
void	ft_draw_ray_line(t_game *game)
{
	double	inv;

	inv = 1 / game->ratio;
	game->br.x1 = (int)(game->ray.hit_x * inv);
	game->br.y1 = (int)(game->ray.hit_y * inv);
	init_draw_line(game);
	draw_line(game, RAY);
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
	distance = ft_cali_fisheye(game, player);
	wall = ft_hit_wall(&game->ray);
	ft_cast_wall(game, distance, column, wall);
	draw_map(game, game->size_mini, WALL, SPACE);
	draw_player(game, game->size_mini_player, PLAYER);
	ft_draw_ray_line(game);
	return (0);
}
