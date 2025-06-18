/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:34:42 by liyu              #+#    #+#             */
/*   Updated: 2025/06/18 23:51:10 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

ft_cast_wall(double distance)
{
    int start_y = (HEIGHT - height) / 2;
    int end = start_y + height;
    while(start_y < end)
    {
        put_pixel(i, start_y, 255, game);
        start_y++;
    }
}

