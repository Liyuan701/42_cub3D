/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:43:04 by lifan             #+#    #+#             */
/*   Updated: 2025/07/11 19:14:38 by yren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* format attendu : "identifiant chemin/vers/texture.xpm"
//* supprimer les espace puis malloc avec mylloc
//* contrôler que le chemin se termine par .xpm
//* essayer d'ouvrir
void	check_xpm_exit(t_game *game, char *line)
{
	int		len;
	char	*path;

	path = mylloc_value(game, line);
	if (path == NULL)
		ft_error_close(game, "texture config: format path invalid");
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + (len - 4), ".xpm", 4) != 0)
		ft_error_close(game, "Texture config: must end with .xpm");
	if (access(path, R_OK) != 0)
		ft_error_close(game, "Texture config: path is wrong");
}

//* séparer la ligne en tokens avec ft_split()
//* verifier si c'est des nombres et ses domaine
//* rendre un int hexadecimal 0xRRGGBB
int	check_parse_color(t_game *game, char *line)
{
	int		start;
	char	**rgb;

	start = get_start(line);
	rgb = ft_split(line + start, ',');
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		free_tab_exit(game, rgb, \
			"Color config: must have exactly 3 components");
	if (str_is_digit_space(rgb[0]) == 0
		&& str_is_digit_space(rgb[1]) == 0 && str_is_digit_space(rgb[2]) == 0)
	{
		game->config.r = ft_atoi(rgb[0]);
		game->config.g = ft_atoi(rgb[1]);
		game->config.b = ft_atoi(rgb[2]);
	}
	else
		free_tab_exit(game, rgb, "Color config: must be digit");
	if (game->config.r < 0 || game->config.r > 255
		|| game->config.g < 0 || game->config.g > 255
		|| game->config.b < 0 || game->config.b > 255)
		free_tab_exit(game, rgb, \
			"Color config: components out of range 0-255");
	ft_free_tab(rgb);
	return ((game->config.r << 16) | (game->config.g << 8) | game->config.b);
}

//sauter les espcaes puis verifier si c'est un de NO SO WE EA F C
//si oui return index, sinon -1
int	is_config_index(char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	if (ft_strlen(str) >= 3 && ft_strncmp(str, "NO", 2) == 0
		&& ft_isspace(str[2]) != 0)
		return (0);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "SO", 2) == 0
		&& ft_isspace(str[2]) != 0)
		return (1);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "WE", 2) == 0
		&& ft_isspace(str[2]) != 0)
		return (2);
	else if (ft_strlen(str) >= 3 && ft_strncmp(str, "EA", 2) == 0
		&& ft_isspace(str[2]) != 0)
		return (3);
	else if (ft_strlen(str) >= 2 && ft_isspace(str[1]) != 0 && str[0] == 'F')
		return (4);
	else if (ft_strlen(str) >= 2 && ft_isspace(str[1]) != 0 && str[0] == 'C')
		return (5);
	else
		return (-1);
}

//* trouver index
//* --> verifier pour la repetition avec seen
//* --> verifier si c'est dans l'ordre
//* respecter la forme pour le couleur et le path
void	check_config_line(t_game *game, t_config *c, char *line)
{
	c->index = is_config_index(line);
	if (c->index == -1)
		ft_error_close(game, "Configuration: invalid format");
	if (c->seen[c->index] == 1)
		ft_error_close(game, "Configuration: Duplicate");
	c->seen[c->index] = 1;
	if (c->index < 4)
		check_xpm_exit(game, line);
	else
		check_parse_color(game, line);
	c->count++;
}

//* avoir 6 correct config
//* arret devant l'info de map
void	check_config(t_game *game, t_config *c)
{
	int	i;

	i = 0;
	c->count = 0;
	init_seen(c->seen);
	while (i < game->cub->nl && c->count < 6)
	{
		if (ft_str_isspace(game->cub->text[i]) == 1)
		{
			i++;
			continue ;
		}
		check_config_line(game, c, game->cub->text[i]);
		i++;
	}
	if (c->count < 6)
		ft_error_close(game, "Configuration: Missing config entries");
	game->cub->end_config = i;
	ft_find_start(game, game->cub->text, i);
}
