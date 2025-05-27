/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:13:37 by lifan             #+#    #+#             */
/*   Updated: 2024/07/23 14:42:43 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fm, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, fm);
	while (fm[i])
	{
		if (fm[i] == '%' && fm[i + 1])
		{
			i++;
			ft_case(&arg, &count, fm[i]);
			i++;
		}
		else
		{
			ft_char((char)fm[i], &count);
			i++;
		}
	}
	va_end(arg);
	return (count);
}

void	ft_case(va_list *arg, int *count, char fm)
{
	if (fm == 'c')
		ft_char(va_arg(*arg, int), count);
	else if (fm == '%')
		ft_char('%', count);
	else if (fm == 's')
		ft_string(va_arg(*arg, char *), count);
	else if (fm == 'p')
		ft_pointer(va_arg(*arg, size_t), count);
	else if (fm == 'i' || fm == 'd')
		ft_nb(va_arg(*arg, int), count);
	else if (fm == 'u')
		ft_unint(va_arg(*arg, unsigned int), count);
	else if (fm == 'x')
		ft_hex(va_arg(*arg, unsigned int), count, 'x');
	else if (fm == 'X')
		ft_hex(va_arg(*arg, unsigned int), count, 'X');
	else if (!ft_is(fm))
		ft_two(fm, count);
}

int	ft_is(char fm)
{
	if (fm == 'c' || fm == '%' || fm == 's' || fm == 'p' || fm == 'i'
		|| fm == 'u' || fm == 'x' || fm == 'X')
		return (1);
	return (0);
}
