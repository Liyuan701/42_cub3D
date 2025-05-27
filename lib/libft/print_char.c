/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:01:30 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 14:43:06 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_two(char c, int *count)
{
	char	a;

	a = '%';
	write(1, &a, 1);
	write(1, &c, 1);
	(*count) += 2;
}

void	ft_string(char *arg, int *count)
{
	size_t	i;

	i = 0;
	if (!arg)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (arg[i])
	{
		ft_char(arg[i], count);
		i++;
	}
}
