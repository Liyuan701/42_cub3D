/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:44:28 by lifan             #+#    #+#             */
/*   Updated: 2025/06/27 17:20:18 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* ft_memeset all to NUll and 0, but for color -1.
#include "../include/cub3D.h"

static	void	ft_init_player(t_player *player)
{
	player->x = -1.0;
	player->y = -1.0;
	player->xp = 0;
	player->yp = 0;
	player->dir = '\0';
	player->color = -1;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	// player->left_rotate = false;
	// player->right_rotate = false;
	//! init player
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
}

void	ft_init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->head = NULL;
	game->status = PARSE;
	game->height = HEIGHT;
	game->width = WIDTH;
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
}
