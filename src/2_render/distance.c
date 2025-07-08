/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:18:57 by lifan             #+#    #+#             */
/*   Updated: 2025/07/08 18:33:24 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_distance_lr(t_game *game)
{
	if (game->ray.step_x > 0)
		game->ray.hit_x = game->ray.map_x * game->size_mini;
	else
		game->ray.hit_x = (game->ray.map_x + 1) * game->size_mini;
	game->ray.hit_y = game->player->m_yp
		+(game->ray.hit_x - game->player->m_xp)
		* (game->ray.vector_y / game->ray.vector_x);
}

void	ft_distance_ud(t_game *game)
{
	if (game->ray.step_y > 0)
		game->ray.hit_y = game->ray.map_y * game->size_mini;
	else
		game->ray.hit_y = (game->ray.map_y + 1) * game->size_mini;
	game->ray.hit_x = game->player->m_xp
		+ (game->ray.hit_y - game->player->m_yp)
		* (game->ray.vector_x / game->ray.vector_y);
}

//* calculate the distance from the point to (x,y)
//* m_xp, m_yp is the init x,y in size_mini.
double	ft_distance(t_game *game)
{
	double	dx;
	double	dy;

	if (game->ray.hit_side == 0)
		ft_distance_lr(game);
	else if (game->ray.hit_side == 1)
		ft_distance_ud(game);
	if (game->ray.hit_x != -1 && game->ray.hit_y != -1)
	{
		dx = game->ray.hit_x - game->player->m_xp;
		dy = game->ray.hit_y - game->player->m_yp;
		return (sqrt(dx * dx + dy * dy));
	}
	return (ft_error_close(game, "error in hit wall"), 0.0);
/*	printf("hit_x = %.2f, hit_y = %.2f, hit_side = %d\n",
		game->ray.hit_x, game->ray.hit_y, game->ray.hit_side);*/
}

//* correct the fish-eye effect by fixing the ray distance
//* cast the long ray with a larger angle to the palyer-angle ray.
double	ft_cali_fisheye(t_game *game, t_player *player)
{
	double	angle_ray;
	double	angle_diff;
	double	dist;

	angle_ray = atan2(game->ray.vector_y, game->ray.vector_x);
	angle_diff = angle_ray - player->angle;
	dist = ft_distance(game);
	return (dist * cos(angle_diff));
}
