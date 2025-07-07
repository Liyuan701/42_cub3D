/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:56 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 15:13:02 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* draw the line from (x0, y0) to (x1, y1)
void	ft_draw_ray_line(t_game *game)
{
	game->br.x0 = game->ray.pl_x + game->size_mini_player / 2;
	game->br.y0 = game->ray.pl_x + game->size_mini_player / 2;
	game->br.x1 = (int)(game->ray.hit_x * game->size_mini / game->size_block);
	game->br.y1 = (int)(game->ray.hit_y * game->size_mini / game->size_block);
	printf("x0: %d, y0: %d, x1: %d, y1: %d\n", game->br.x0, game->br.y0, game->br.x1, game->br.y1); //! DEBUG
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
	ft_draw_ray_line(game);
	return (0);
}
