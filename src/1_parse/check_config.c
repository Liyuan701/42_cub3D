#include "../include/cub3D.h"

void	check_xpm_exit(t_game *game, char *line)
{
	int len;
	char **split;
	int fd;

	split = ft_split(line, ' ');
	len = ft_strlen(split[1]);
	if (split[0] == NULL && split[1] == NULL && split[2] != NULL)
		// ft_free_tab(split);
		ft_error_close(game, "Error: Invalid texture config format");
	if (len < 4 || ft_strncmp(split[1] + (len - 4), ".xpm", 4) != 0)
		// ft_free_tab(split);
		ft_error_close(game, "Error: Texture must end with .xpm");
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		// ft_free_tab(split);
		ft_error_close(game, "Error: Texture path is wrong");
	}
	close(fd);
	//free split
}

int is_config_index(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (ft_strlen(str) >= 3 && ft_strncmp(str, "NO", 2) == 0 &&  ft_isspace(str[2]) != 0)
		return(0);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "SO", 2) == 0 && ft_isspace(str[2]) != 0)
		return(1);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "WE", 2) == 0 && ft_isspace(str[2]) != 0)
		return(2);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "EA", 2) == 0 && ft_isspace(str[2]) != 0)
		return(3);
	else if (ft_strlen(str) >= 2 && ft_isspace(str[1]) != 0 && str[0] == 'F')
		return (4);
	else if (ft_strlen(str) >= 2 && ft_isspace(str[1]) != 0 && str[0] == 'C')
		return (5);
	else
		return (-1);
}

int	check_parse_color(t_game *game, char *line)
{
	char	**split_line;
	char	**rgb;
	int		r;
	int		g;
	int		b;

	split_line = ft_split(line, ' ');
	rgb = ft_split(split_line[1], ',');
	if (split_line[0] == NULL || split_line[1] == NULL || split_line[2] != NULL)
		ft_error_close(game, "Error: Invalid color config format");//need to free
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		ft_error_close(game, "Error: Color must have exactly 3 components");//need to free
	if (str_is_digit(rgb[0]) != 0 && str_is_digit(rgb[1]) != 0 && str_is_digit(rgb[2]) != 0)
	{
		r = ft_atoi(rgb[0]);
		g = ft_atoi(rgb[1]);
		b = ft_atoi(rgb[2]);
	}
	else
		ft_error_close(game, "Error: Color config must be digit");//need to free
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0|| b > 255)
		ft_error_close(game, "Error: Color components out of range 0-255");//need to free
	// free_split(rgb);
	// free_split(split_line);
	return (r << 16) | (g << 8) | b;
}

//trouver index
//verifier pour la repetition
//verifier si c'est dans l'ordre
//respecter la forme pour le couleur et path
//arret devant l'info de map
//avoir 6 config
void	check_config(t_map *map, t_game *game)
{
	int i;
	int count;
	int index;
	int	last_index;
	bool	seen[6];
	
	i = 0;
	count = 0;
	last_index = -1;
	init_seen(seen);
	while(i < map->line && count < 6)
	{
		if (map->text[i] == NULL || map->text[i][0] == '\0')
		{
			i++;
			continue;
		}
		index = is_config_index(map->text[i]);
		if (index == -1)
			ft_error_close(game, "Error: Invalid format configuration");	
		if (seen[index] == true)
			ft_error_close(game, "Error: Duplicate configuration");
		seen[index] = true;
		if (index <= last_index)
			ft_error_close(game, "Error: Config entries out of order");
		last_index = index;
		if (index < 4)
			check_xpm_exit(game, map->text[i]);
		else
			check_parse_color(game, map->text[i]);
		count++;
		i++;
	}
	if(count < 6)
		ft_error_close(game, "Error: Missing config entries");
	map.end_config = i;
}

