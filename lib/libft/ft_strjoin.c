/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:05 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 18:33:46 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2) + 1));
	if (out == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		out[i + j] = s2[j];
		j++;
	}
	out [i + j] = '\0';
	return (out);
}
