/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:28:22 by yren              #+#    #+#             */
/*   Updated: 2025/06/25 14:51:40 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//*trouver la pos de pixel sur l'image
//size_line --> nb d'octets par ligne de pixels
//bpp --> nombre de bits utilisés pour chaque pixel
//1 octet = 8 bit
//bleu  0-7；green 8-15 ；red   16-32
//0xFF --> prend les 8 dernier
void	put_pixel(t_game *game, int x, int y, int color)
{
	int	position;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	position = y * game->tex->size_line + x * game->tex->bpp / 8;
	game->tex->addr[position] = color & 0xFF;
	game->tex->addr[position + 1] = (color >> 8) & 0xFF;
	game->tex->addr[position + 2] = (color >> 16) & 0xFF;
}

//* noircir l'image
void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, 0);
			x++;
		}
		y++;
	}
}

//* dessiner un ensemble de pixel --> square
//* set size_square
void	draw_square(t_pixel *p, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(p->game, p->x + i, p->y + j, color);
			j++;
		}
		i++;
	}
}
