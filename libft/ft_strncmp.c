/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:02:28 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 16:45:57 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1 [i] != '\0' || s2 [i] != '\0'))
	{
		if (s1 [i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h> 
int	main(void)
{
	printf("%d\n",ft_strncmp("I AM THE STRING S1","I AM THE STRING S2",2));
	printf("%d\n",ft_strncmp("not same 1","not same 2",10));
	printf("%d",ft_strncmp("4","",0));
	return (0);
}*/
