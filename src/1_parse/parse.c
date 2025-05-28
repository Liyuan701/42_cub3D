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

//* malloc each line in the game->map->text tab.
//! MYLLOC
static void	ft_fill_text(t_game *game, char **text, int fd)
{
	int		i;
	int		row;
	int		col;
	char	*line;

	i = 0;
	row = 0;
	col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->cub->text[row] = \
			ft_mylloc(game, (ft_strlen(line) + 1) * sizeof(char));
		if (!game->cub->text[row])
			ft_error_close(game, "can't malloc a line in the tab");
		while (line[i] != '\0')
			game->cub->text[row][col++] = line[i++];
		game->cub->text[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	game->cub->text[row] = NULL;
}

//* malloc a **text tab, and copy all contenus in the .cub
//! MYLLOC
int	ft_get_text(t_game *game, char *file)
{
	int		nl;
	int		fd;

	nl = 0;
	game->cub->nl = ft_count_lines(game, file);
	game->cub->text = (char **)
		ft_mylloc((game, game->cub->nl + 1) * sizeof(char *));
	if (!(game->cub->text))
		return (ft_error("Can't malloc the text tab."), FAIL);
	fd = open(file, O_RDONLY);
	game->cub->op_fd = fd;
	ft_fill_text(game, game->cub->text, fd);
	close (fd);
	game->cub->op_fd = -1;
	return (0);
}

//* Here, we malloc all info in the .cub file.
//* Split the map and other info
//* Check if map and other info are valide
int	ft_parse(t_game *game, char *file)
{
	if (ft_get_text(game, file) == FAIL)
		return (ft_error_close(game, "can't get the file."), 1);
	if (ft_get_config(game, game->cub->text) == FAIL)
		return (ft_error_close(game, "can't get the config."), 1);
	if (ft_get_map(game, game) == FAIL)
		return (ft_error_close(game, "can't get the map.", 1));
	if (ft_check_map(game, game->cub->copy) == FAIL)
		return (ft_error_close(game, "invalid map"), 1);
	return (0);
}
