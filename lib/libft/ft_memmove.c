/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:21:01 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 18:11:26 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src <= dst)
	{
		i = num;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < num)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main (void)
{
	char	src[50] = "it's what we want you to see. \n";
	char	dst[50] = "it's to be replaced.\n";
	ft_memmove(dst, src, 20);
	printf("After memmove>> dst =%s\n src = %s\n",dst,src);
	return (0);
}*/
