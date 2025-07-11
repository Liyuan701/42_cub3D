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
		game->ray.side_x = (game->player->pos_x \
			- game->ray.map_x) * game->ray.d_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_x = (game->ray.map_x \
			+ 1.0 - game->player->pos_x) * game->ray.d_x;
	}
	if (game->ray.vector_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_y = (game->player->pos_y \
			- game->ray.map_y) * game->ray.d_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_y = (game->ray.map_y \
		+ 1.0 - game->player->pos_y) * game->ray.d_y;
	}
}

//* d_x/d_y the distance passed when we move a x or a y.
//* side_x side_y, current distance to the nearest x or y.
//*fabs double absolute value.
void	ft_init_ray(t_game *game, double dir, int column)
{
	game->ray.vector_x = cos(dir);
	game->ray.vector_y = sin(dir);
	game->ray.hit_x = -1;
	game->ray.hit_y = -1;
	game->ray.map_x = (int)game->player->pos_x;
	game->ray.map_y = (int)game->player->pos_y;
	if (game->ray.vector_x == 0)
		game->ray.d_x = 1e30;
	else
		game->ray.d_x = fabs(1 / game->ray.vector_x);
	if (game->ray.vector_y == 0)
		game->ray.d_y = 1e30;
	else
		game->ray.d_y = fabs(1 / game->ray.vector_y);
	game->ray.hit[column].x = -1;
	game->ray.hit[column].y = -1;
	ft_side_ray(game);
}

//* chose the longest dis, and move.
//* dis is game->ray.side_x += game->ray.d_x or y. it's not the coor.
//* verify if touch the wall
//* hit_side == 1 horizontale aka y.
//* hit side == 0 vertical aka x.
bool	ft_if_encounter(t_game *game)
{
	while (1)
	{
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
}
