/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:34:42 by liyu              #+#    #+#             */
/*   Updated: 2025/07/11 20:18:41 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* Put the celling and ground colors in imgae
void	ft_draw_floor(t_game *game, int y, int column)
{
	while (y < HEIGHT)
	{
		put_pixel(game, column, y, game->config.floor);
		y++;
	}
}

//* for the chosen column, get each pixel color from top to bottom.
//* dis_plane is the middle pendicule distance.
void	ft_cast_wall(t_game *game, double distance, int column, char side)
{
	t_wall	*wall;
	int		y;
	int		dis_plane;
	int		tex_y_off;

	wall = &game->wall;
	ft_memset(wall, 0, sizeof(t_wall));
	ft_select_wall(game, side, wall);
	dis_plane = (WIDTH / 2) / tan(PI / 3 / 2);
	ft_def_wall(wall, game, distance, dis_plane);
	y = 0;
	while (y < wall->start_y)
	{
		put_pixel(game, column, y, game->config.ceiling);
		y++;
	}
	while (y < wall->end_y)
	{
		tex_y_off = (y - wall->start_y) + wall->off_y;
		wall->tex_y = tex_y_off * wall->tex->height / wall->wall_height;
		wall->color = get_tex_color(wall->tex, wall->tex_x, wall->tex_y);
		put_pixel(game, column, y, wall->color);
		y++;
	}
	ft_draw_floor(game, y, column);
}
