/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:56 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 13:10:31 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_draw_ray_line(t_game *game)
{
	game->br.x0 = (int)(game->player->x * game->size_mini + game->size_mini / 2);
	game->br.y0 = (int)(game->player->y * game->size_mini + game->size_mini / 2);
	game->br.x1 = (int)(game->ray.ray_x * game->size_mini);
	game->br.y1 = (int)(game->ray.ray_y * game->size_mini);
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
	ft_draw_ray_line(game);
	distance = ft_cali_fisheye(game, player);
	wall = ft_hit_wall(&game->ray);
	ft_cast_wall(game, distance, column, wall);
	return (0);
}
