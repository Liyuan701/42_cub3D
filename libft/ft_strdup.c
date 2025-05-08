/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:48:53 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 14:09:58 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src [i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int	main()
{
	char src[] = "Hello it's a test";
	printf("%s\n", ft_strdup(src));
}*/
