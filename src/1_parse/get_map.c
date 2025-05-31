/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:39:30 by lifan             #+#    #+#             */
/*   Updated: 2025/05/10 18:39:30 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* WIth the given map->end_config
//* we will copy the rest and creat map.

#include "../include/cub3D.h"

//* If enconter blank line in/after the map, error.
static int	ft_count_map(t_game *game, char **text, int i)
{
	int		count;
	int		j;

	count = 0;
	while (text[i])
	{
		j = 0;
		while (text[i][j] && ft_isspace(text[i][j]))
			j++;
		if (text[i][j] == '\0')
			ft_error_close(game, "There are blank lines in/after the map.");
		if (ft_find(text[i][j], " 01NWES") == 1)
		{
			count++;
			i++;
		}
		else
			ft_error_close(game, "Invalid symbols in/after the map.");
	}
	return (count);
}

static	void	ft_no_others(t_game *game, char **map)
{
	int	y;
	int	x;
	int	h;
	int	w;

	y = 0;
	h = game->cub->height;
	w = game->cub->width;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (ft_find(map[y][x], " 01NEWS") == 0)
				ft_error_close(game, "There are invalid symbols in the map.");
			x++;
		}
		y++;
	}
}

//* copy a map for the test
//* this map have the same width, fill with espaces.
static	void	ft_copy_map(t_game *game)
{
	int	i;
	int	len;
	int	height;
	int	width;

	i = 0;
	len = 0;
	height = game->cub->height;
	width = game->cub->width;
	game->cub->copy = ft_mylloc(game, (height + 1) * sizeof(char *));
	while (i < height)
	{
		game->cub->copy[i] = ft_mylloc(game, (width + 1));
		ft_memset(game->cub->copy[i], ' ', width);
		game->cub->copy[i][width] = '\0';
		ft_strlcpy(game->cub->copy[i], \
			game->cub->map[i], ft_strlen(game->cub->map[i]));
		i++;
	}
	game->cub->copy[i] = NULL;
	ft_no_others(game, game->cub->copy);
	ft_flood_map(game, game->cub->copy);
}

//* we creat the map from the text.
int	ft_get_map(t_game *game)
{
	int		start;
	int		i;
	int		col_w;

	i = 0;
	start = game-> cub ->start;
	game->cub->height = ft_count_map(game, game->cub->text, start);
	game->cub->map = ft_mylloc(game, (game->cub->height + 1));
	while (i < game->cub->height)
	{
		col_w = ft_strlen(game->cub->text[start]);
		game->cub->map[i] = ft_mylloc(game, (col_w + 1) * sizeof(char));
		if (col_w > game->cub->width)
			game->cub->width = col_w;
		ft_strlcpy(game->cub->map[i], game->cub->text[start], col_w + 1);
		i++;
		start++;
	}
	ft_copy_map(game);
	return (0);
}

int	ft_find_start(t_game *game, char **text, int i)
{
	int		j;

	while (text[i])
	{
		j = 0;
		while (text[i][j] && ft_isspace(text[i][j]))
			j++;
		if (text[i][j] == '\0')
		{
			i++;
			continue ;
		}
		if (ft_find(text[i][j], "01NEWS "))
		{
			game->cub->start = i;
			return (0);
		}
		i++;
	}
	ft_error_close(game, "There is no map in the .cub file.");
	return (1);
}
