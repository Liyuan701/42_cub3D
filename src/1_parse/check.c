/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:08:36 by lifan             #+#    #+#             */
/*   Updated: 2025/05/08 14:08:36 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


//TODO  here we check if they are valide args.

int	ft_check_args(int ac, char **av)
{
	if (ac <= 1)
		return (ft_error("There is no argument."), 1);
	else if (ac > 2)
		return (ft_error("There are too many arguments."), 1);
	else if (ft_not_cub(av[1]))
		return (ft_error("It's not a .cub file."), 1);
	return (0);
}

int	ft_not_cub(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ft_memcmp(&str[i], ".cub", 4))
		return (FAIL);
	retrun (0);
}
