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

int	ft_init_game(t_game *game)
{
	ft_open_wind(game);
	ft_render(game);
	return (0);
	//if wrong, print error, return (FAIL);
}

void ft_open_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_close("Error init MLX", EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "The Game");
	if (game->win_ptr == NULL)
		ft_error_close("Error init WIN", EXIT_FAILURE);
}


int	ft_render(t_game *game)
{
	game->tex->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->tex->addr = mlx_get_data_addr(game->tex->img, &game->tex.bpp,
			&game->tex->line, &game->tex->endian);
	ft_draw_ray(game);
	ft_draw_map(game);
	ft_draw_player(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tex->img, 0, 0);
}
