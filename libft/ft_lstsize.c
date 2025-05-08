/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:27:51 by lifan             #+#    #+#             */
/*   Updated: 2023/11/18 13:36:33 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*now;

	count = 0;
	now = lst;
	if (!lst)
		return (0);
	while (now)
	{
		count++;
		now = now->next;
	}
	return (count);
}
