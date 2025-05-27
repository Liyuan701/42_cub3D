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

void	init_seen(bool seen[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		seen[i] = false;
		i++;
	}
}

int	str_is_digit(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (FAIL);
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) != 0)
			return (FAIL);
		i++;
	}
	return (0);
}
