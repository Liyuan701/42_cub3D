/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:29:12 by lifan             #+#    #+#             */
/*   Updated: 2025/05/10 17:29:12 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_find(char *str, char c)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (str[i])
	{
		if (str[i] == c)
			find = 1;
		i++;
	}
	return (find);
}

//* Make sure every letter in the map is one of the 5 letters.
//* And N E S W only appears once.
int	ft_check_onlyc(t_game *game)
{
	int		y;
	int		x;
	char	c;
	int		count;

	y = 0;
	count = 0;
	while (y < game->cub->height)
	{
		x = 0;
		while (x < game->cub->width)
		{
			c = game->cub->map[x][y];
			if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
				count++;
			if (ft_find("01NSW", c) == 0 || count > 1)
				return (FAIL);
			x++;
		}
		y++;
	}
	return (0);
}

//* Check that all walls are closed.
//* Only have valide characters.
int	ft_check_map(t_game *game)
{
	if (ft_check_around(game->cub->copy))
		return (FAIL);
	if (ft_check_onlyc(game))
		return (FAIL);
	if (ft_check_waLL(game))
		return (FAIL);
	return (0);
}
