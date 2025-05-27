/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:14:57 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:09:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int a)
{
	if (a <= 122 && a >= 97)
		return (a - 32);
	return (a);
}

/*#include <stdio.h>

int	main(void)
{
	char a = 'a';
	char B = 'B';
	char c = '?';
	printf("%d\n", ft_toupper(a));
	printf("%d\n", ft_touppet(B));
	printf("%d\n", ft_toupper(c));
}*/
