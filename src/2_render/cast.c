/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:34:42 by liyu              #+#    #+#             */
/*   Updated: 2025/06/24 01:00:51 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char    hit_wall(t_ray *ray)
{
    if (ray->hit_side == 0)
	{
		if (ray->step_x > 0)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (ray->step_y > 0)
			return ('S');
		else
			return ('N');
	}
}

t_tex   *ft_select_wall(t_game *game, char wall)
{
    if (wall == 'N')
        return (&game->tex_n);
    else if (wall == 'S')
        return (&game->tex_s);
    else if (wall == 'E')
        return (&game->tex_e);
    else if (wall == 'W')
        return (&game->tex_w);
}

int calculate_tex_x(t_game *game, t_tex *tex, double dist)
{
    double wall_x;
    int tex_x;

    if (game->ray.hit_side == 0) 
        wall_x = game->player->y + dist * game->ray.vector_y;
    else
        wall_x = game->player->x + dist * game->ray.vector_x;
    wall_x -= floor(wall_x); 
    tex_x = (int)(wall_x * (double)tex->width);
    if (game->ray.hit_side == 0 && game->ray.vector_x > 0)
        tex_x = tex->width - tex_x - 1;
    if (game->ray.hit_side == 1 && game->ray.vector_y < 0)
        tex_x = tex->width - tex_x - 1;
    return tex_x;
}

int get_tex_color(t_tex *tex, int x, int y)
{
    char    *pixel;

    if (x < 0)
        x = 0;
    if (x >= tex->width)
        x = tex->width - 1;
    if (y < 0)
        y = 0;
    if (y >= tex->height)
        y = tex->height - 1;
    pixel = tex->addr + y * tex->size_line + x * (tex->bpp / 8);
    return (*(int *)pixel);
}

void	ft_cast_wall(t_game *game, double distance, int column, char side)
{
    t_wall  *wall;
    int     y;

    wall = &game->wall;
    ft_memset(wall, 0, sizeof(t_wall));
    wall->tex = ft_select_wall(game, side);
	wall->wall_height = (int)((BLOCK / distance) * (WIDTH / 2.0));
	wall->start_y = (HEIGHT - wall->wall_height) / 2;
	if (wall->start_y < 0)
		wall->start_y = 0;
	wall->end_y = wall->start_y + wall->wall_height;
	if (wall->end_y > HEIGHT)
		wall->end_y = HEIGHT;
	wall->tex_x = calculate_tex_x(game, wall->tex, distance);
	y = wall->start_y;
	while (y < wall->end_y)
	{
		wall->tex_y = (y - wall->start_y) * wall->tex->height / wall->wall_height;
		wall->color = get_tex_color(wall->tex, wall->tex_x, wall->tex_y);
		put_pixel(game, column, y, wall->color);
		y++;
	}
}