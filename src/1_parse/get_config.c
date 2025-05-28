#include "../include/cub3D.h"

char	*get_ptr(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		i += 2;
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		i += 1;
	while (ft_isspace(str[i]))
		i++;
	return (str + i);
}

void	ft_get_config(t_game *game)
{
	int		i;
	int		index;
	char	*line;
	char	*line_ptr;

	i = 0;
	check_config(game->cub);
	while (i < game->cub->end_config)
	{
		line = game->cub->text[i];
		if (line == NULL || *line == '\0')
		{
			i++;
			continue ;
		}
		index = is_config_index(line);
		line_ptr = get_ptr(line);
		if (index == 0)
			game->config.no = line_ptr;
		else if (index == 1)
			game->config.so = line_ptr;
		else if (index == 2)
			game->config.we = line_ptr;
		else if (index == 3)
			game->config.ea = line_ptr;
		else if (index == 4)
			game->config.floor = check_parse_color(game, line);
		else if (index == 5)
			game->config.ceiling = check_parse_color(game, line);
		i++;
	}
	if (game->config.no == NULL || game->config.so == NULL
		|| game->config.we == NULL || game->config.ea == NULL
		|| game->config.floor < 0 || game->config.ceiling < 0)
		ft_error_close(game, "Error: Failed to get all config values");
}
