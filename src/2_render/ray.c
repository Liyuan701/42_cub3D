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

//* from the player, draw ray.
//* angle = dorection, use radians.
//* DDA algotithme, by block.
 int	ft_draw_ray(t_game *game, t_player *player, float angle, int column)
 {
    double  distance;

    game->ray.vector_x = cos(angle);
    game->ray.vector_y = sin(angle);
    game->ray.ray_x = player->x;
    game->ray.ray_y = player->y;
    game->ray.map_x = (int)(game->ray.ray_x / BLOCK);
    game->ray.map_x = (int)(game->ray.ray_y / BLOCK);
    ft_distance(game->ray);
    ft_cali_fisheye(game, player, game->ray);
    ft_cast_wall(game, distance);
}

 


//* calculate the distance from the point to (x,y)
 double  ft_distance(float x, float y)
 {

 }


 //*correct the fish-eye effect by fixing the ray distance
 float  ft_cali_fisheye(t_game *game, float x, float y, float a, float b)
 {

 }


 //*verify if touch the wall
 bool   ft_if_encounter(t_game *game, float x, float y)
 {

 }