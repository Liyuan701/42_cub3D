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

//* load four wall texs.
int	ft_load_tex(t_game	*game)
{
	if (!load_texture(game->mlx_ptr, game->config.no, &game->tex_n))
		return (ft_error_close(game, \
			"Can't load the north wall texture."), FAIL);
	if (!load_texture(game->mlx_ptr, game->config.so, &game->tex_s))
		return (ft_error_close(game, \
			"Can't load the south wall texture."), FAIL);
	if (!load_texture(game->mlx_ptr, game->config.ea, &game->tex_e))
		return (ft_error_close(game, \
			"Can't load the east wall texture."), FAIL);
	if (!load_texture(game->mlx_ptr, game->config.we, &game->tex_w))
		return (ft_error_close(game, \
			"Can't load the west wall texture."), FAIL);
	return (0);
}

//* load one wall tex.
int	load_texture(void *mlx_ptr, char *path, t_tex *tex)
{
	int	width;
	int	height;

	tex->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, \
		&tex->size_line, &tex->endian);
	tex->width = width;
	tex->height = height;
	if (!tex->addr)
	{
		mlx_destroy_image(mlx_ptr, tex->img);
		return (0);
	}
	return (1);
}

//* creat new image.
//* access to the buffer.
//* load all four walls.
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
	game->tex->addr = mlx_get_data_addr(game->tex->img,
			&game->tex->bpp, &game->tex->size_line, &game->tex->endian);
	ft_load_tex(game);
}

//* put buffer in windows.
void	ft_render(t_game *game)
{
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

	game = (t_game *)param;
	i = 0;
	fraction = PI / 3 / WIDTH;
	dir = game->player->angle - PI / 6;
	move_player(game, game->player);
	clear_image(game);
	draw_map(game, game->map.size_mini, WALL, SPACE);
	draw_player_mini(game, game->map.size_mini, PLAYER);
	while (i < WIDTH)
	{
		ft_ray(game, game->player, dir, i);
		dir += fraction;
		i++;
	}
	ft_render(game);
	return ;
}
