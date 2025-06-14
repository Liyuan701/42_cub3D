/* ************************************************************************** */
/*								                                            */
/*                                                        :::      ::::::::   */
/*   config_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:09:28 by yren              #+#    #+#             */
/*   Updated: 2025/06/13 18:09:58 by yren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char *replace_space(char *line)
{
    int i;

    i = 0;
	while (line[i] != '\0') 
    {
		if (line[i] == '\t' || line[i] == '\r' || line[i] == '\v' || line[i] == '\f') 
		{
			line[i] = ' ';
		}
		i++;
	}
	return (line);
}

void	free2tab_exit(t_game *game, char **tab1, char **tab2, char *error_msg)
{
	ft_free_tab(tab1);
	ft_free_tab(tab2);
	ft_error_close(game, error_msg);
}