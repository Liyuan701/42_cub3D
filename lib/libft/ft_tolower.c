/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:30:46 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:09:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int a)
{
	if (a <= 90 && a >= 65)
		return (a + 32);
	return (a);
}

/*#include <stdio.h>

int	main(void)
{
	char a = 'a';
	char B = 'B';
	char c = '?';
	printf("%d\n", ft_tolower(a));
	printf("%d\n", ft_tolower(B));
	printf("%d\n", ft_tolower(c));
}*/
