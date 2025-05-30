/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:29:12 by lifan             #+#    #+#             */
/*   Updated: 2025/05/30 13:29:02 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* To be sure that the O and NWES are not on the boders
//* Or they are not connected to an espace.
static	void	ft_check_wall(t_game *game, char **map, int y, int x)
{
	int	reso;

	reso = 0;
	if (y == 0 || (y > 0 && map[y - 1][x] == 'V'))
		reso = FAIL;
	if (!map[y + 1] || (map[y + 1] && map[y + 1][x] == 'V'))
		reso = FAIL;
	if (x == 0 || (x > 0 && map[y][x - 1] == 'V'))
		reso = FAIL;
	if (map[y][x + 1] == '\0' || map[y][x + 1] == 'V')
		reso = FAIL;
	if (reso == FAIL)
		ft_error_close(game, "Wall of the map is not closed");
}

//* Must have, and only have one player.
static	void	ft_set_player(t_game *game, char c, int y, int x)
{
	if (game->player->dir || game->player->x != -1.0 || game->player->y != -1.0)
		ft_error_close("There are more than one player position.");
	else
	{
		game->player->x = x + 0.5;
		game->player->y = y + 0.5;
		game->player->dir = c;
		if (c == 'E')
			game->player->dir_x = 1;
		if (c == 'W')
			game->player->dir_x = -1;
		if (c == 'N')
			game->player->dir_y = 1;
		if (c == 'S')
			game->player->dir_y = -1;
		game->cub->copy[y][x] = '0';
		ft_check_wall(game, game->cub->copy, y, x);
	}
}

//* Check that all walls are closed (No free '0' or 'NWES')
//* Only have valide characters.
int	ft_check_map(t_game *game, char **map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map[y])
	{
		x = 0;
		c = map[y][x];
		while (c)
		{
			if (c == '0')
				ft_check_wall(game, map, y, x);
			else if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
				ft_set_player(game, c, y, x);
			else if (c != 'V' && c != '1')
				return (ft_error("There \
					are invalid symbols in the map."), FAIL);
			x++;
		}
		y++;
	}
	if (game->player->x == -1 || !game->player->y == -1 || !game->player->dir)
		return (ft_error("Can't set the player's position."), FAIL);
	return (0);
}
