/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:09 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 16:16:08 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	out = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (out == NULL)
		return (NULL);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
