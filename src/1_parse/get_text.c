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

//* Here, we malloc all info in the .cub file.
//* Split the map and other info
//* Check if map and other info are valide

int	ft_parse(t_game *game, char *file)
{
	if (ft_get_text(game, file) == FAIL)
		return (ft_close(game), 1);
	if (ft_split_info_map(game, game->map->text) == FAIL)
		return (ft_close(game), 1);
	if (ft_check_other(game, game->config) == FAIL)
		return (ft_close(game), 1);
	if (ft_check_map(game, game->map) == FAIL)
		return (ft_close(game), 1);
	return (0);
}

int	ft_get_text(t_game *game, char *file)
{
	int		line;

	line = 0;
	game->map->line = ft_count_lines(file);
	game->map->text = (char **)\
	ft_mylloc((game, game->map->line + 1) * sizeof(char *));
	if (!(game->map->text))
		return (ft_error("Can't malloc the text tab."), FAIL);
	ft_fill_text(game, game->map->text, line);
	return (0);
}

static void	ft_fill_text(t_game *game, char **text, int row)
{
	int		i;
	int		column;
	char	*line;

	i = 0;
	column = 0;
	line = get_next_line(game->map->fd);
	while (line != NULL)
	{
		game->map->text[row] = ft_mylloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->map->text[row])
		{
			ft_error("Can't malloc the line in the tab.");
			ft_close(game);
		}
		while (line[i] != '\0')
			game->map->text[row][column++] = line[i++];
		game->map->text[row++][column] = '\0';
		column = 0;
		i = 0;
		ft_free_one(game, line);
		line = get_next_line(game->map->fd);
	}
	game->map->text[row] = NULL;
}
