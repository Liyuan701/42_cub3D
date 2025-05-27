/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:44:28 by lifan             #+#    #+#             */
/*   Updated: 2025/05/27 11:57:18 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* ft_memeset all to NUll and 0, but for color -1.
#include "../include/cub3D.h"

void	ft_init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(map));
}

void	ft_init_tex(t_tex *tex)
{
	ft_memset(tex, 0, sizeof(tex));
}

void	ft_init_player(t_player *player)
{
	ft_memset(player, 0, sizeof(player));
}

//!For Yongyue
void	ft_init_config(t_game *game)
{
	//set all to 0 or -1.
}
