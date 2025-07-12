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

void	free_tab_exit(t_game *game, char **tab, char *error_msg)
{
	ft_free_tab(tab);
	ft_error_close(game, error_msg);
}
