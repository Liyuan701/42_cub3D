/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:34:44 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 16:26:05 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
		{
			nbr = nbr * 10 + (*str - '0');
			str++;
		}
		return (sign * nbr);
	}
	return (0);
}

/*#include <stdio.h>

int	ft_atoi(const char *str);
int	main(void)
{
	printf("%d\n", ft_atoi("42t4457"));
	printf("%d\n", ft_atoi("-24sfs"));
	printf("%d\n", ft_atoi("\01337"));
	printf("%d\n", ft_atoi("+42"));
	printf("%d\n", ft_atoi("--243 2 5"));
}*/
