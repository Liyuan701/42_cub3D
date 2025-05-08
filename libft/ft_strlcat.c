/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:51:21 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:09:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0 || size < dlen)
		return (slen + size);
	while (src [i] && i + dlen + 1 < size)
	{
		dest [dlen + i] = src [i];
		i++;
	}
	dest [dlen + i] = '\0';
	return (dlen + slen);
}

/*#include <stdio.h>
#include <string.h> 
int	main(void)
{
	char dest[] = "the first one and ";
	char src[] = "the second one";
	printf("%i\n",ft_strlcat(dest,src,20));
	printf("%s\n",dest);
	return (0);
}*/
