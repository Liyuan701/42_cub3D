/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:44:28 by lifan             #+#    #+#             */
/*   Updated: 2025/05/30 13:42:52 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* ft_memeset all to NUll and 0, but for color -1.
#include "../include/cub3D.h"

static	void	ft_init_player(t_player *player)
{
	player->x = -1.0;
	player->y = -1.0;
	player->dir = NULL;
	player->dir_x = 0;
	player->dir_y = 0;
	player->color = -1;
	player->turn = 0;
	player->forward = 0;
}

static	void	ft_init_config(t_game *game)
{
	game->config.no = NULL;
	game->config.so = NULL;
	game->config.we = NULL;
	game->config.ea = NULL;
	game->config.floor = -1;
	game->config.ceiling = -1;
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
	ft_memset(game->tex, 0, sizeof(game->tex));
	ft_memset(game->cub, 0, sizeof(game->cub));
	ft_init_player(game->player);
}
