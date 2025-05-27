/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:34:29 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 14:41:29 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nb(int nb, int *count)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_char('-', count);
		ft_nb(nb * -1, count);
		return ;
	}
	if (nb > 9)
		ft_nb(nb / 10, count);
	ft_char(nb % 10 + '0', count);
}

void	ft_hex(unsigned int nb, int *count, char c)
{
	char	*base;
	char	str[17];
	int		i;

	i = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_char('0', count);
		return ;
	}
	while (nb != 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	while (i--)
		ft_char(str[i], count);
}

// char	*ft_setbase( char c)
// {
// 	int	i;

// 	i = 0;
// 	if (c == 'X')
// 		return("123456789ABCDEF");
// 	else
// 		return("123456789abcdef");

// }

void	ft_unint(unsigned int nb, int *count)
{
	if (nb > 9)
		ft_unint(nb / 10, count);
	ft_char(nb % 10 + '0', count);
}

void	ft_pointer(size_t ptr, int *count)
{
	char	str[17];
	int		i;
	char	*base;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	i = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	(*count) += 2;
	if (ptr == 0)
		ft_char('0', count);
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_char(str[i], count);
}
