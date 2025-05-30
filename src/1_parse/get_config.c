/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:56:59 by lifan             #+#    #+#             */
/*   Updated: 2025/05/30 13:56:59 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	get_start(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0 || ft_strncmp(line + i, "SO", 2) == 0
		|| ft_strncmp(line + i, "WE", 2) == 0 \
		|| ft_strncmp(line + i, "EA", 2) == 0)
		i += 2;
	else if (ft_strncmp(line + i, "F", 1) == 0 \
		|| ft_strncmp(line + i, "C", 1) == 0)
		i += 1;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

char	*mylloc_value(t_game *game, char *line)
{
	int		start;
	int		end;
	int		len;
	char	*value;

	start = get_start(line);
	end = start;
	while (line[end] != '\0' && ft_isspace(line[end]) == 0)
		end++;
	len = end - start;
	value = ft_mylloc(game, len + 1);
	if (value == NULL)
		return (NULL);
	ft_memcpy(value, line + start, len);
	value[len] = '\0';
	return (value);
}

void	get_index_value(char *line, t_game *game)
{
	int	index;

	index = is_config_index(line);
	if (index == 0)
		game->config.no = mylloc_value(game, line);
	else if (index == 1)
		game->config.so = mylloc_value(game, line);
	else if (index == 2)
		game->config.we = mylloc_value(game, line);
	else if (index == 3)
		game->config.ea = mylloc_value(game, line);
	else if (index == 4)
		game->config.floor = check_parse_color(game, line);
	else if (index == 5)
		game->config.ceiling = check_parse_color(game, line);
}

void	ft_get_config(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	check_config(game, &game->config);
	while (i < game->cub->end_config)
	{
		line = game->cub->text[i];
		if (ft_str_isspace(line) == 1)
		{
			i++;
			continue ;
		}
		get_index_value(line, game);
		i++;
	}
	if (game->config.no == NULL || game->config.so == NULL
		|| game->config.we == NULL || game->config.ea == NULL
		|| game->config.floor < 0 || game->config.ceiling < 0)
		ft_error_close(game, "Get config: Failed to get all config values.");
}
