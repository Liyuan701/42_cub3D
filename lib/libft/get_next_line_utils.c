/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:46:58 by lifan             #+#    #+#             */
/*   Updated: 2023/12/18 17:47:46 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strleng(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchrg(char *str, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strleng(str)]);
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoing(char *got, char *buff)
{
	char	*new;

	if (!got)
	{
		got = (char *)malloc(sizeof(char));
		if (!got)
			return (NULL);
		got[0] = '\0';
	}
	if (!got || !buff)
		return (free(got), NULL);
	new = malloc(ft_strleng(got) + ft_strleng(buff) + 1);
	if (!new)
		return (NULL);
	new = ft_join(new, got, buff);
	return (new);
}

char	*ft_join(char *new, char *got, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (got)
	{
		while (got[i])
		{
			new[i] = got[i];
			i++;
		}
	}
	while (buff[j])
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	free(got);
	return (new);
}

char	*ft_copy(char *got, char *line)
{
	int	i;

	i = 0;
	while (got[i] && got[i] != '\n')
	{
		line[i] = got[i];
		i++;
	}
	if (got[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
