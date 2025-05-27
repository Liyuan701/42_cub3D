/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:26:44 by lifan             #+#    #+#             */
/*   Updated: 2023/11/18 15:49:01 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		now = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = now;
	}
}
