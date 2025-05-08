/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:37:58 by lifan             #+#    #+#             */
/*   Updated: 2025/05/08 15:37:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//TODO here, we allocate the map, and read the cub, check if they are valide.

int	ft_init_map()
{
	ft_allocate_map();
	ft_get_map();
	return(ft_check_map());
}

int	ft_check_map()
{
	if (ft_color() || ft_setting() || ft_texture())
		return (FAIL);
	return (0);
}
