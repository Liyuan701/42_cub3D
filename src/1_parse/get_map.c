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

static	void	ft_no_v(t_game *game, char **map)
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
			if (map[y][x] == 'V')
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
	game->cub->copy = mylloc(game, (height + 1) * sizeof(char *));
	while (i < height)
	{
		game->cub->copy[i] = mylloc(game, (width + 1));
		ft_memeset(game->cub->copy[i], ' ', width);
		game->cub->copy[i][width] = '\0';
		ft_strlcpy(game->cub->copy[i], \
			game->cub->map[i], ft_strlen(game->cub->map[i]));
		i++;
	}
	game->cub->copy[i] = NULL;
	ft_no_v(game, game->cub->copy);
	ft_flood_map(game, game->cub->copy);
}

//* we creat the map from the text.
void	ft_get_map(t_game *game)
{
	int		start;
	int		i;
	size_t	col_w;

	i = 0;
	start = game-> cub ->start;
	game->cub->height = ft_count(game->cub->text, start);
	game->cub->map = mylloc(game, (game->cub->height + 1));
	while (i < game->cub->height)
	{
		col_w = ft_strlen(game->cub->text[start]);
		game->cub->map[i] = mylloc(game, (col_w + 1) * sizeof(char));
		if (col_w > game->cub->width)
			game->cub->width = col_w;
		ft_strlcpy(game->cub->map[i], game->cub->text[start], col_w + 1);
		i++;
		start++;
	}
	ft_copy_map(game);
}

void	ft_find_start(t_game *game, char **text, int i)
{
	int		j;
	char	c;

	while (text[i])
	{
		j = 0;
		c = text[i][j];
		while (c && ft_isspace((unsigned char)c))
			j++;
		if (!c)
		{
			i++;
			continue ;
		}
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			game->cub->start = i;
		i++;
	}
	ft_error_close("There is no map in the .cub file.");
}
