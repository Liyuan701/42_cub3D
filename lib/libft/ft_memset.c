/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:21:19 by lifan             #+#    #+#             */
/*   Updated: 2023/11/12 15:27:05 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)p)[i] = (unsigned char)value;
		i++;
	}
	return (p);
}
