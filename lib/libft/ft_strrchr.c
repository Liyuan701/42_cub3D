/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:23 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 12:15:38 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*right;

	i = 0;
	right = NULL;
	while (str[i])
	{
		if (((char *)str)[i] == (char)c)
			right = &((char *)str)[i];
		i++;
	}
	if (((char *)str)[i] == (char)c)
		right = &((char *)str)[i];
	return (right);
}
