/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:42:57 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 18:02:50 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	find;

	i = 0;
	str = (unsigned char *)s;
	find = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == find)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
