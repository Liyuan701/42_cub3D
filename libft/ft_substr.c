/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:31 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 11:36:15 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sublen;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	sublen = len;
	if (start + len > i)
		sublen = i - start;
	if (start >= i)
		sublen = 0;
	sub = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
