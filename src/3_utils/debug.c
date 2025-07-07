/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:28:45 by lifan             #+#    #+#             */
/*   Updated: 2025/07/07 16:52:46 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <string.h>

int	print_player(t_player *p)
{
	if (!p)
		return (printf("Player is NULL\n"), FAIL);
	printf("=== PLAYER ===\n");
	printf("Position: (%d, %d)\n", p->init_x, p->init_y);
	printf("Direction: %c ", p->dir);
	printf("Color: 0x%X\n", p->color);
	printf("\n");
	return (0);
}

int	print_cub(t_cub *c)
{
	if (!c)
		return (printf("Cub is NULL\n"), FAIL);
	printf("=== CUB ===\n");
	printf("Number of lines: %d\n", c->nl);
	printf("Width: %d, Height: %d\n", c->width, c->height);
	printf("End config index: %d\n", c->start);
	printf("Text content:\n");
	printf("\n");
	printf("Map:\n");
	printf("\n");
	return (0);
}

int	print_config(t_config *cfg)
{
	if (!cfg)
		return (printf("Config is NULL\n"), FAIL);
	printf("=== CONFIG ===\n");
	printf("NO: %s\n", cfg->no);
	printf("SO: %s\n", cfg->so);
	printf("WE: %s\n", cfg->we);
	printf("EA: %s\n", cfg->ea);
	printf("Floor color: 0x%X\n", cfg->floor);
	printf("Ceiling color: 0x%X\n", cfg->ceiling);
	printf("\n");
	return (0);
}

int	ft_debug_parse(t_game *game)
{
	if (!game)
		return (printf("Game is Null\n"), FAIL);
	printf("=== GAME ===\n");
	printf("Window size: %d x %d\n", game->width, game->height);
	printf("Status: %d\n", game->status);
	print_config(&game->config);
	print_cub(game->cub);
	print_player(game->player);
	printf("\n");
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
