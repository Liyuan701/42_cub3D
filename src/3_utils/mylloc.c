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

//* It's my malloc tracker
//* add malloc pointer to the chain, so we hava a record, and can free then all.
//* when need malloc, simply ptr = mylloc(game, size);
//* Keep the head as the toppest one.

void *ft_mylloc(t_game *game, size_t size)
{
	void	*new;

	new = malloc(size);
    if (!new)
        return NULL;

    t_track *node = malloc(sizeof(t_track));
    if (!node)
    {
        free(new);
        return NULL;
    }
    node->ptr = new;
    node->next = game->head;
    game->head = node;
    return new;
}
