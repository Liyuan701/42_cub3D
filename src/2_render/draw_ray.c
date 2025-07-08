/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:56 by lifan             #+#    #+#             */
/*   Updated: 2025/07/08 18:32:35 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* draw the line from (x0, y0) to (x1, y1)
void	ft_draw_one_ray(t_game *game, double x1, double y1)
{
	game->br.x0 = (int)game->player->m_xp + game->size_mini_player / 2;
	game->br.y0 = (int)game->player->m_yp + game->size_mini_player / 2;
	game->br.x1 = (int)x1;
	game->br.y1 = (int)y1;
	init_draw_line(game);
	draw_line(game, RAY);
}

void	ft_draw_all_ray(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ft_draw_one_ray(game, game->ray.hit[i].x, game->ray.hit[i].y);
		i++;
	}
}

void	ft_save_end_ray(t_game *game, int column)
{
	game->ray.hit[column].x = game->ray.hit_x;
	game->ray.hit[column].y = game->ray.hit_y;
}

//* from the player, draw ray.
//* angle = direction, use radians.
//* DDA algotithme, by block.
int	ft_ray(t_game *game, t_player *player, double dir, int column)
{
	double	distance;
	char	wall;

	ft_init_ray(game, dir, column);
	if (!ft_if_encounter(game))
		ft_error_close(game, "Wired, the ray didn't reach the wall.");
	distance = ft_cali_fisheye(game, player);
	wall = ft_hit_wall(&game->ray);
	ft_cast_wall(game, distance, column, wall);
	int mini_hit_x = game->ray.hit_x / game->size_mini * game->size_mini;
	int mini_hit_y = game->ray.hit_y / game->size_mini * game->size_mini;
	put_pixel(game, mini_hit_x, mini_hit_y, 0xFF0000);
	ft_save_end_ray(game, column);
	return (0);
}
