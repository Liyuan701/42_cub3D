/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:32:00 by liyu              #+#    #+#             */
/*   Updated: 2025/06/16 22:32:00 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* the suite of the ft_init_ray.
//* step means dir. +: towards right (x+)or down(y+);
//* -:towards left (x-)or up(y-).
//* we don't start from an angle of the square
//* so calculate the left dis side_x, side_y.
//* side_x : the distance to the next vertical line.
//* side_y : the distance to the next horizontal line.
static void	ft_side_ray(t_game *game)
{
	if (game->ray.vector_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_x = (game->ray.ray_x \
			- game->ray.map_x * game->size_block) * game->ray.d_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_x = ((game->ray.map_x \
			+ 1) * game->size_block - game->ray.ray_x) * game->ray.d_x;
	}
	if (game->ray.vector_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_y = (game->ray.ray_y \
			- game->ray.map_y * game->size_block) * game->ray.d_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_y = ((game->ray.map_y \
		+ 1) * game->size_block - game->ray.ray_y) * game->ray.d_y;
	}
}

//* d_x/d_y the distance passed when we move a x or a y.
//* side_x side_y, current distance to the nearest x or y.
void	ft_init_ray(t_game *game, double dir)
{
	game->ray.vector_x = cos(dir);
	game->ray.vector_y = sin(dir);
	game->ray.hit_x = -1;
	game->ray.hit_y = -1;
	game->ray.ray_x = game->player->m_xp;
	game->ray.ray_y = game->player->m_yp;
	game->player->b_xp = game->player->m_xp * game->size_block / game->size_mini;
	game->player->b_yp = game->player->m_yp * game->size_block / game->size_mini;
	game->ray.d_x = fabs(game->size_block / game->ray.vector_x);
	game->ray.d_y = fabs(game->size_block / game->ray.vector_y);
	ft_side_ray(game);
}

//* chose the longest dis, and move.
//* dis is game->ray.side_x += game->ray.d_x or y. it's not the coor.
//* verify if touch the wall
//* hit_side == 1 horizontale aka x
//* hit side == 0 vertical aka y.
bool	ft_if_encounter(t_game *game)
{
	while (1)
	{
		printf("The start point: x = %d, y = %d\n", game->player->init_x, game->player->init_y);
		printf("The start point: map_x = %d, map_y = %d, side_x = %f, side_y = %f\n",
			game->ray.map_x, game->ray.map_y, game->ray.side_x, game->ray.side_y);
		if (game->ray.side_x < game->ray.side_y)
		{
			game->ray.side_x += game->ray.d_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.hit_side = 0;
		}
		else
		{
			game->ray.side_y += game->ray.d_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.hit_side = 1;
		}
		if (game->ray.map_x < 0 || game->ray.map_x >= game->cub->width)
			ft_error_close(game, "x depass the map");
		if (game->ray.map_y < 0 || game->ray.map_y >= game->cub->height)
			ft_error_close(game, "y depass the map");
		if (game->cub->copy[game->ray.map_y][game->ray.map_x] == '1')
			return (true);
	}
	return (false);
}

//* calculate the distance from the point to (x,y)
double	ft_distance(t_game *game)
{
	double	dx;
	double	dy;

	if (game->ray.hit_side == 0)
		game->ray.hit_x = game->ray.map_x * game->size_block;
	else
		game->ray.hit_x = game->ray.ray_x \
		+ (game->ray.side_x - game->ray.d_x) * game->ray.vector_x;
	if (game->ray.hit_side == 1)
		game->ray.hit_y = game->ray.map_y * game->size_block;
	else
		game->ray.hit_y = game->ray.ray_y \
		+ (game->ray.side_y - game->ray.d_y) * game->ray.vector_y;
	if (game->ray.hit_x != -1 && game->ray.hit_y != -1)
	{
		dx = game->ray.hit_x - game->player->b_xp;
		dy = game->ray.hit_y - game->player->b_yp;
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
