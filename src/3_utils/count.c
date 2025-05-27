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
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count);
}
