/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:22:58 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 12:10:34 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;
	char	find;

	i = 0;
	s = (char *)str;
	find = (char)c;
	while (s[i])
	{
		if (s[i] == find)
			return (&s[i]);
		i++;
	}
	if (s[i] == find)
		return (&s[i]);
	return (NULL);
}
