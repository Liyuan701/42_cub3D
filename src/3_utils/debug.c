/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:28:45 by lifan             #+#    #+#             */
/*   Updated: 2025/06/19 00:17:08 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <string.h>

int	print_player(t_player *p)
{
	if (!p)
		return (printf("Player is NULL\n"), FAIL);
	printf("=== PLAYER ===\n");
	printf("Position: (%.2f, %.2f)\n", p->x, p->y);
	printf("Direction: %c (dir_x: %d, dir_y: %d)\n", p->dir, p->dir_x, p->dir_y);
	printf("Color: 0x%X\n", p->color);
	printf("Forward: %d, Turn: %d\n", p->forward, p->turn);
	printf("\n");
	return(0);
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
	for (int i = 0; c->text && c->text[i]; i++)
		printf("%s\n", c->text[i]);
	printf("\n");
	printf("Map:\n");
	for (int i = 0; c->map && c->map[i]; i++)
		printf("%s\n", c->map[i]);
	printf("\n");
	return(0);
	
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
	return(0);
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
	return(0);
}

void	print_map(char **map)
{
	int	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void ft_draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(game->mlx, game->win, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void ft_draw_ray_line(t_game *game)
{
    int start_x = (int)game->player->x;
    int start_y = (int)game->player->y;
    int end_x;
    int end_y;

    if (game->ray.hit_side == 0)
        end_x = game->ray.map_x * BLOCK;
    else
        end_x = (int)(game->ray.ray_x + (game->ray.side_x - game->ray.d_x) * game->ray.vector_x);

    if (game->ray.hit_side == 1)
        end_y = game->ray.map_y * BLOCK;
    else
        end_y = (int)(game->ray.ray_y + (game->ray.side_y - game->ray.d_y) * game->ray.vector_y);

    ft_draw_line(game, start_x, start_y, end_x, end_y, RAY);
}