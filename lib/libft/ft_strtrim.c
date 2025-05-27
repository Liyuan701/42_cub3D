/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:28 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 13:22:07 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (c == ((char *)set)[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_empty(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_isset(s1[i], set) == 1)
		i++;
	if (i == len)
		return (ft_empty());
	while (ft_isset(s1[len - 1], set) == 1)
		len--;
	out = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, (char *)&s1[i], len - i + 1);
	return (out);
}
