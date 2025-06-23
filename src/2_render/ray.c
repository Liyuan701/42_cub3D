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

//* d_x/d_y the distance cost move to next x or y
//* side_x side_y, current distance to the nearest x or y.
void ft_init_ray(t_game *game, t_player *player)
{
    game->ray.map_x = (int)(game->ray.ray_x / BLOCK);
    game->ray.map_y = (int)(game->ray.ray_y / BLOCK);
    game->ray.d_x = fabs(BLOCK / game->ray.vector_x);
    game->ray.d_y = fabs(BLOCK / game->ray.vector_y);
    if (game->ray.vector_x < 0)
    {
        game->ray.step_x = -1;
        game->ray.side_x = (game->ray.ray_x - game->ray.map_x * BLOCK) * game->ray.d_x;
    }
    else
    {
        game->ray.step_x = 1;
        game->ray.side_x = ((game->ray.map_x + 1) * BLOCK - game->ray.ray_x) * game->ray.d_x;
    }

    if (game->ray.vector_y < 0)
    {
        game->ray.step_y = -1;
        game->ray.side_y = (game->ray.ray_y - game->ray.map_y * BLOCK) * game->ray.d_y;
    }
    else
    {
        game->ray.step_y = 1;
        game->ray.side_y = ((game->ray.map_y + 1) * BLOCK - game->ray.ray_y) * game->ray.d_y;
    }
}

 //* verify if touch the wall
 //* hit_side == 1 horizontale, == 0 vertical.
 bool   ft_if_encounter(t_game *game)
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
        if (game->cub->copy[game->ray.map_y][game->ray.map_x] == '1')
            return (true);
    }
    return (false);
}

//* calculate the distance from the point to (x,y)
 double  ft_distance(t_game *game)
 {
    double  hit_x;
    double  hit_y;

    if (game->ray.hit_side == 0)
        hit_x = game->ray.map_x * BLOCK;
    else
        hit_x = game->ray.ray_x + (game->ray.side_x - game->ray.d_x) * game->ray.vector_x;
    if (game->ray.hit_side == 1)
        hit_y = game->ray.map_y * BLOCK;
    else
        hit_y = game->ray.ray_y + (game->ray.side_y - game->ray.d_y) * game->ray.vector_y;
    double dx = hit_x - game->player->x;
    double dy = hit_y - game->player->y;
    return (sqrt(dx * dx + dy * dy));
 }


 //* correct the fish-eye effect by fixing the ray distance
 //* cast the long ray with a larger angle to the palyer-angle ray.
 double  ft_cali_fisheye(t_game *game, t_player *player)
 {
    double  angle_ray;
    double  angle_diff;
    double  dist;

    angle_ray = atan2(game->ray.vector_y, game->ray.vector_x);
    angle_diff = angle_ray - player->angle;
    dist = ft_distance(game);
    return (dist * cos(angle_diff)); 
 }

//* from the player, draw ray.
//* angle = dorection, use radians.
//* DDA algotithme, by block.
int	ft_draw_ray(t_game *game, t_player *player, float angle, int column)
 {
    double  distance;
    char    wall;

    game->ray.vector_x = cos(angle);
    game->ray.vector_y = sin(angle);
    game->ray.ray_x = player->x;
    game->ray.ray_y = player->y;
    game->ray.map_x = (int)(game->ray.ray_x / BLOCK);
    game->ray.map_y = (int)(game->ray.ray_y / BLOCK);
    ft_init_ray(game, game->player);
    if (!ft_if_encounter(game))
        ft_error_close(game, "Wired, the ray didn't reach the wall.");
    ft_draw_ray_line(game);//!DEBUG
    distance = ft_cali_fisheye(game, player);
    wall = ft_hit_wall(&game->ray);
    ft_cast_wall(game, distance, column, wall);
}