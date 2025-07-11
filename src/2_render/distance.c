/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:18:57 by lifan             #+#    #+#             */
/*   Updated: 2025/07/11 15:31:26 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_distance_lr(t_game *game, double centre_x, double centre_y)
{
	if (fabs(game->ray.vector_x) < EPSILON)
	{
		game->ray.hit_x = centre_x;
		game->ray.hit_y = centre_y + game->ray.side_y;
		return ;
	}
	if (game->ray.step_x > 0)
		game->ray.hit_x = game->ray.map_x * game->size_mini;
	else
		game->ray.hit_x = (game->ray.map_x + 1) * game->size_mini;
	game->ray.hit_y = game->player->m_yp
		+(game->ray.hit_x - game->player->m_xp)
		* (game->ray.vector_y / game->ray.vector_x);
}

void	ft_distance_ud(t_game *game, double centre_x, double centre_y)
{
	if (fabs(game->ray.vector_y) < 0.001)
	{
		game->ray.hit_y = centre_y;
		game->ray.hit_x = centre_x + game->ray.side_x;
		return ;
	}
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
	double	centre_x;
	double	centre_y;

	centre_x = game->player->m_xp;
	centre_y = game->player->m_yp;
	if (game->ray.hit_side == 0)
		ft_distance_lr(game, centre_x, centre_y);
	else if (game->ray.hit_side == 1)
		ft_distance_ud(game, centre_x, centre_y);
	else
		ft_error_close(game, "Error: Can't find the hit_side");
	if (game->ray.hit_x != -1 && game->ray.hit_y != -1)
	{
		dx = game->ray.hit_x - game->player->m_xp;
		dy = game->ray.hit_y - game->player->m_yp;
		return (sqrt(dx * dx + dy * dy));
	}
	return (ft_error_close(game, "error in hit wall"), 0.0);
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
