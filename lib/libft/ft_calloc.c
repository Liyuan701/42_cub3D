/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:04:54 by lifan             #+#    #+#             */
/*   Updated: 2023/11/23 13:49:20 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	all;
	void	*out;

	if (nmemb == 0 || size == 0)
	{
		out = (void *) malloc(0);
		if (!out)
			return (NULL);
		return (out);
	}
	all = nmemb * size;
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	out = malloc(all);
	if (out == NULL)
		return (NULL);
	else
		ft_bzero(out, all);
	return (out);
}
