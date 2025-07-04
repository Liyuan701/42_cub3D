/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 07:08:48 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 07:08:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* hit_side == 0 means vertical side, W or E.
//* hit_side == 1 means horizontal side, N or S.
//* step_x > 0  , ray to the right, E， the seen block, W.
//* step_y > 0, ray downwards, S, the seen block N.
char	ft_hit_wall(t_ray *ray)
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

void	ft_select_wall(t_game *game, char side, t_wall *wall)
{
	if (side == 'N')
		wall->tex = &game->tex_n;
	else if (side == 'S')
		wall->tex = &game->tex_s;
	else if (side == 'E')
		wall->tex = &game->tex_e;
	else if (side == 'W')
		wall->tex = &game->tex_w;
}
//* block = 1 unit, only keep the num after . to know its pos in the block.
//* when hit E/W, precision is in y (dis * v_y : how much moves in y direction)
//* when hit S/W, precision is in x (dis * v_x : how much moves in x direction).
int	calculate_tex_x(t_game *game, t_tex *tex, double dist)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.hit_side == 0)
		wall_x = game->player->y + dist * game->ray.vector_y;
	else
		wall_x = game->player->x + dist * game->ray.vector_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	return (tex_x);
}
//* make sur that the x, y don't go out the tex.
//* get the (x,y) pixel's address.
//* each pixel bpp bits,and convert to bytes.
//* move y lines and x bytes. each line size_line bytes.
int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*pixel;

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

//* start_y the top of the wall, end_y the bottom of the wall.
//* it's the top of Height or to make the wall in the middle of the Height.
//* pixel coor need to be int.
//* chose the column in the tex: calculate_tex_x.
void	ft_def_wall(t_wall *wall,t_game *game, double distance, int dis_plane)
{
	wall->wall_height = (int)((game->size_block / distance) * dis_plane);
	wall->start_y = (HEIGHT / 2) - (wall->wall_height / 2);
	if (wall->start_y < 0)
		wall->start_y = 0;
	wall->end_y = wall->start_y + wall->wall_height;
	if (wall->end_y > HEIGHT)
		wall->end_y = HEIGHT;
	wall->tex_x = calculate_tex_x(game, wall->tex, distance);
}