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

//true = 1
//false = 0
void	init_seen(int seen[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		seen[i] = 0;
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

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

//non --> 0, oui --> 1
int	ft_str_isspace(char *str)
{
	int	i;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
