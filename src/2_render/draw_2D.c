/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:28:22 by yren              #+#    #+#             */
/*   Updated: 2025/06/16 19:02:59 by yren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
    int offset;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
        
	offset = y * game->size_line + x * game->bpp / 8;
    game->data[offset] = color & 0xFF;
    game->data[offset + 1] = (color >> 8) & 0xFF;
    game->data[offset + 2] = (color >> 16) & 0xFF;
}
