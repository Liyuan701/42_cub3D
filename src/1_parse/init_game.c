/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:44:28 by lifan             #+#    #+#             */
/*   Updated: 2025/07/11 20:11:24 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* ft_memeset all to NUll and 0, but for color -1.
#include "../include/cub3D.h"

void	ft_init_player(t_player *player)
{
	player->init_x = -1;
	player->init_y = -1;
	player->m_xp = 0.0;
	player->m_yp = 0.0;
	player->b_xp = 0.0;
	player->b_yp = 0.0;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir = '\0';
	player->color = -1;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

static	void	ft_init_config(t_game *game)
{
	game->config.no = NULL;
	game->config.so = NULL;
	game->config.we = NULL;
	game->config.ea = NULL;
	game->config.floor = -1;
	game->config.ceiling = -1;
	game->config.r = 0;
	game->config.g = 0;
	game->config.b = 0;
	game->wall.off_y = 0;
}

void	ft_init_move(t_game *game)
{
	game->move.speed = 0;
	game->move.angle_speed = 0;
	game->move.cos_angle = 0;
	game->move.sin_angle = 0;
	game->move.cos_speed = 0;
	game->move.sin_speed = 0;
	game->move.size_player = 0;
	game->move.new_xp = 0;
	game->move.new_yp = 0;
	game->br.distance_x = 0;
	game->br.distance_y = 0;
	game->br.dir_x = 0;
	game->br.dir_y = 0;
	game->br.error = 0;
	game->br.error2 = 0;
	game->br.x0 = -1;
	game->br.y0 = -1;
	game->br.x1 = -1;
	game->br.y1 = -1;
}

static void	ft_init_in_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->head = NULL;
	game->status = PARSE;
	game->height = HEIGHT;
	game->width = WIDTH;
	game->size_line = 0;
	game->ratio = -1.0;
	game->size_block = 0.0;
	game->size_mini = 0.0;
	game->size_mini_player = 0.0;
	ft_memset(&game->wall, 0, sizeof(t_wall));
}

void	ft_init_game(t_game *game)
{
	ft_init_in_game(game);
	ft_init_config(game);
	game->cub = ft_mylloc(game, sizeof(t_cub));
	if (!game->cub)
		exit(EXIT_FAILURE);
	game->tex = ft_mylloc(game, sizeof(t_tex));
	if (!game->tex)
		exit(EXIT_FAILURE);
	ft_memset(game->tex, 0, sizeof(t_tex));
	ft_memset(game->cub, 0, sizeof(t_cub));
	game->player = ft_mylloc(game, sizeof(t_player));
	if (!game->player)
		exit(EXIT_FAILURE);
	ft_init_player(game->player);
	ft_init_move(game);
}
