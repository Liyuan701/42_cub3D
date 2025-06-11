/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:30:14 by lifan             #+#    #+#             */
/*   Updated: 2025/06/11 16:36:26 by yren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* From the top, go through all to find the ptr.
int	free_one(t_game *game, void *ptr)
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

//* free all malloc thing in the tab
void	ft_free_all(t_game *game)
{
	t_track	*tmp;

	while (game->head)
	{
		tmp = game->head;
		game->head = game->head->next;
		free(tmp->ptr);
		free(tmp);
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_clean(t_game	*game)
{
	if (game->cub->op_fd > 0)
		close(game->cub->op_fd);
	if (game->status == PARSE)
		ft_free_all(game);
	else if (game->status == GAME)
	{
		mlx_destroy_image(game->mlx_ptr, game->tex->img);
		ft_free_all(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
	}
}
