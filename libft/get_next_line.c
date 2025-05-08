/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:44:54 by lifan             #+#    #+#             */
/*   Updated: 2023/12/18 18:08:33 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *got)
{
	int		len_l;
	char	*line;

	len_l = 0;
	if (!got[len_l])
		return (NULL);
	while (got[len_l] && got[len_l] != '\n')
		len_l++;
	if (got[len_l] == '\0')
		len_l++;
	else
		len_l += 2;
	line = (char *)malloc(sizeof(char) * len_l);
	if (!line)
		return (NULL);
	line = ft_copy(got, line);
	return (line);
}

char	*ft_get_rest(char *got)
{
	int		len_l;
	int		i;
	char	*new;

	len_l = 0;
	while (got[len_l] && got[len_l] != '\n')
		len_l++;
	if (!got[len_l])
	{
		free(got);
		return (NULL);
	}
	new = malloc(ft_strleng(got) - len_l + 1);
	if (!new)
		return (NULL);
	len_l++;
	i = 0;
	while (got[len_l])
		new[i++] = got[len_l++];
	new[i] = '\0';
	free(got);
	return (new);
}

char	*ft_get(int fd, char *got)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchrg(got, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		got = ft_strjoing(got, buff);
	}
	free(buff);
	return (got);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*got[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	got[fd] = ft_get(fd, got[fd]);
	if (!got[fd])
		return (NULL);
	line = ft_get_line(got[fd]);
	got[fd] = ft_get_rest(got[fd]);
	return (line);
}
