/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:48:03 by lifan             #+#    #+#             */
/*   Updated: 2025/05/10 17:48:03 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_count_lines(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_close(game, "can't open the file.");
	while ((line = get_next_line(fd)) != NULL)
		{
			count++;
			free(line);
		}
	close(fd);
	return (count);
}

//*calculate the max width of the map.
void	ft_count_width(t_game *game, int height, int start)
{
	int	i;
	int	col_w;

	i = 0;
	while (i < height)
	{
		col_w = ft_strlen(game->cub->text[start + i]);
		if (col_w > game->cub->width)
			game->cub->width = col_w;
		i++;
	}
}	

//* if can't find, return 0
//* if find, return 1
int	ft_find(char c, char *str)
{
	int	i;
	int	find;

	i = 0;
	find = 0;
	while (str[i])
	{
		if (str[i] == c)
			find = 1;
		i++;
	}
	return (find);
}
