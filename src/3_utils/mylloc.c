/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:45:30 by lifan             #+#    #+#             */
/*   Updated: 2025/05/08 14:45:30 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* From the top, go through all to find the ptr.
int	ft_free_one(t_game *game, void *ptr)
{
	t_track	*prev;
	t_track	*curr;

	prev = NULL;
	curr = game->head;
	while (curr)
	{
		if (curr->ptr == ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				game->head = curr->next;
			free(curr->ptr);
			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

//* It's my malloc tracker
//* add malloc pointer to the chain, so we hava a record, and can free then all.
//* when need malloc, simply ptr = mylloc(game, size);
//* Keep the head as the toppest one.

void	*ft_mylloc(t_game *game, size_t size)
{
	void	*new;
	t_track	*node;

	new = malloc(size);
	if (!new)
		ft_error_close(game, "malloc fail.");
	node = malloc(sizeof(t_track));
	if (!node)
	{
		free(new);
		ft_error_close(game, "malloc fail.");
	}
	node->ptr = new;
	node->next = game->head;
	game->head = node;
	return (new);
}
