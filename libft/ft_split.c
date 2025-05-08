/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:21 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 13:06:55 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_malloc_fail(char **new, int len_l)
{
	while (len_l > 0)
		free(new[len_l--]);
	free(new);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static char	*ft_copy(char *innew, char const *s, int end, int len_l)
{
	int	i;

	i = 0;
	while (len_l > 0)
	{
		innew[i] = s[end - len_l];
		len_l--;
		i++;
	}
	innew[i] = '\0';
	return (innew);
}

static char	**ft_getword(char const *s, char c, char **new, int len_w)
{
	int	i;
	int	j;
	int	len_l;

	i = 0;
	j = 0;
	len_l = 0;
	while (j < len_w)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len_l++;
			i++;
		}
		new[j] = (char *)malloc(sizeof(char) * (len_l + 1));
		if (new[j] == NULL)
			return (ft_malloc_fail(new, j));
		ft_copy(new[j], s, i, len_l);
		len_l = 0;
		j++;
	}
	new[j] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	unsigned int	len_w;

	if (!s)
		return (NULL);
	len_w = ft_count(s, c);
	new = (char **)malloc(sizeof(char *) * (len_w + 1));
	if (!new)
		return (NULL);
	new = ft_getword(s, c, new, len_w);
	return (new);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	i;
	char	**test;
	char 	*str = "hello here is a test";
	
		test = ft_split(str, 32);
		while (test[i])
		{
			printf("%s\n", test[i]);
			i++;
		}	
		return (0);
}*/
