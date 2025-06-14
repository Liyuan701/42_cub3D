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
	else
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

char	*mylloc_strdup(t_game *game, const char *src)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	str = ft_mylloc(game, len + 1);
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src [i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*mylloc_value(t_game *game, char *line)
{
	int		start;
	int		len;
	char	*value;

	start = get_start(line);
	if (start == -1)
		return (NULL);
	value = mylloc_strdup(game, line + start);
	if (value == NULL)
		return (NULL);
	len = ft_strlen(value);
	while(len > 0 && ft_isspace(value[len - 1] == 1))
	{
		value[len - 1] = '\0';
		len--;
	}
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


// int	len_without_space(char *src)
// {
// 	int len;
// 	int i;

// 	i = 0;
// 	len = 0;
// 	while(src[i] != 0)
// 	{
// 		if (ft_isspace(src[i]) == 0)
// 			len++;
// 		i++;
// 	}
// 	return(len);
// }

//malloc str without space
// char *mylloc_value(t_game *game, char *line)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	int		start;
// 	char	*value;
// 	char	*tmp;

// 	start = get_start(line);
// 	if (start = -1)
// 		return(NULL);
// 	tmp = line + start;
// 	len = len_without_space(tmp);
// 	value = ft_mylloc(game, len + 1);
// 	if (value == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while(tmp[i] != 0)
// 	{
// 		if (ft_isspace(tmp[i]) == 0)
// 			value[j++] = tmp[i];
// 		i++;
// 	}
// 	value[j] = '\0';
// 	return (value);
// }