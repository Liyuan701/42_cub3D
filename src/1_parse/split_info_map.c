/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_info_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:48:21 by lifan             #+#    #+#             */
/*   Updated: 2025/05/10 18:48:21 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* find the map, get the map, and know wether the map is on the end.

//si text[i] non vide ET pas la format de config -->exit
//si c'est config et avoir 6 fois --> fin de la part de config
int	ft_split_info_map(t_game *game, t_map *map)
{
	int i;
	int count;
	char *str;

	i = 0;
	count = 0;
	while(i < map.line && count < 6)
	{
		str = map.text[i];
		if (map.text[i] != '\0' && is_config(str) == FAIL)
			ft_error_close(game, "Error: Invalid .cub file format");
		if (is_config(str) == 0)
		{
			//get config
			count++;
		}
		i++;
	}
	if (count < 6)
		ft_error_close(game, "Error: Missing config entries");
	map.end_config = i;
}

// 0 -->yes, 1 --> no
//voir si c'est config（NO, SO, WE, EA, F, C）
int is_config(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, "NO", 2) == 0 && ft_isspace(str[2]) != 0)
		return (0);
	if (ft_strncmp(str, "SO", 2) == 0 && ft_isspace(str[2]) != 0)
		return (0);
	if (ft_strncmp(str, "WE", 2) == 0 && ft_isspace(str[2]) != 0)
		return (0);
	if (ft_strncmp(str, "EA", 2) == 0 && ft_isspace(str[2]) != 0)
		return (0);
	if (str[0] == 'F' && ft_isspace(str[1]) != 0)
		return (0);
	if (str[0] == 'C' && ft_isspace(str[1]) != 0)
		return (0);
	return (FAIL);
}
