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

void	ft_refresh(t_game *game)
{
	double	fraction;
	double	dir;
	int		i;
	//TODO: move player with key
	//TODO: clear image
	//TODO: draw_2D;
	i = 0;
	fraction = PI / 3 / WIDTH;
	dir = game->player.angle - PI / 6;
	while (i < WIDTH)
        {
	    ft_draw_ray(game, game->player, dir, i);
	    dir += fraction;
	    i++;
	}
	    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return ;
	}
}

void	ft_open_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_close(game, "init MLX");
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "The Game");
	if (game->win_ptr == NULL)
		ft_error_close(game, "init WIN");
	game->status = GAME;
}

/*void	ft_render(t_game *game) 
{
	game->tex->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->tex->addr = mlx_get_data_addr(game->tex->img, &game->tex->bpp,
			&game->tex->size_line, &game->tex->endian);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tex->img, 0, 0);
}*/
