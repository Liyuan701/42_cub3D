/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:34:56 by lifan             #+#    #+#             */
/*   Updated: 2025/05/08 15:34:56 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_render(t_game *game) 
{
	game->tex->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->tex->addr = mlx_get_data_addr(game->tex->img, &game->tex->bpp,
			&game->tex->size_line, &game->tex->endian);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tex->img, 0, 0);
}

//* each column, draw a ray to calculate wall.
//* VOF = 60, begin with (player angle - 30 = the left). 
void	ft_refresh(void	*param)
{
	t_game	*game;
	double	fraction;
	double	dir;
	int		i;


	//TODO: move player with key
	//TODO: clear image
	//TODO: draw_2D;
	game = (t_game *)param;
	i = 0;
	fraction = PI / 3 / WIDTH;
	dir = game->player->angle - PI / 6;
	while (i < WIDTH)
    {
	    ft_draw_ray(game, game->player, dir, i);
	    dir += fraction;
	    i++;
	}
	ft_render(game);
	return ;
}