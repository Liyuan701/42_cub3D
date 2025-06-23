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

//TODO from here, we begin the game.
#include "../include/cub3D.h"

void	ft_init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_close(game, "init MLX");
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "The Game");
	if (game->win_ptr == NULL)
		ft_error_close(game, "init WIN");
	game->status = GAME;
	game->tex->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->tex->data = mlx_get_data_addr(game->tex->img, &game->tex->bpp,
		&game->tex->size_line, &game->tex->endian);
}

int	ft_refresh(t_game *game)
{
	move_player(game, game->player);
	clear_image(game);
	draw_map(game, game->size_square);
	draw_player(game, game->size_square);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tex->img, 0, 0);
	return (0);
}

