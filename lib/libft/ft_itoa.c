/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:04:20 by lifan             #+#    #+#             */
/*   Updated: 2023/11/15 15:48:47 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*out;
	unsigned int	nb;
	unsigned int	len;

	len = ft_len(n);
	nb = n;
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	out[len] = '\0';
	if (n == 0)
		out[0] = '0';
	if (n < 0)
	{
		out[0] = '-';
		nb = -n;
	}
	while (nb != 0)
	{
		out[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len --;
	}
	return (out);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", ft_itoa(32654189));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}*/
