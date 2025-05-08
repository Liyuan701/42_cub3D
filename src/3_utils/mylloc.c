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

//TODO it's my malloc tracker
//TODO  add malloc pointer to the tab, so we can free then all.


void *mylloc(t_game *game, size_t size)
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
