/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:37 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:54:52 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	m;
	size_t	i;

	i = 0;
	m = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest [i] = src [i];
			i++;
		}
		dest [i] = '\0';
	}
	return (m);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest[] = "12345678";
	char src[] = "abcdefgh";
	ft_strlcpy(dest, src, 5);
	printf("%s", dest);
}*/
