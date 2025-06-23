/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:30:14 by lifan             #+#    #+#             */
/*   Updated: 2025/06/24 00:08:24 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

void	free_texture(void *mlx_ptr, t_tex *tex)
{
	if (tex->img)
		mlx_destroy_image(mlx_ptr, tex->img);
	tex->img = NULL;
}

void	ft_free_all_tex(t_game *game)
{
	free_texture(game->mlx_ptr, &game->tex_n);
	free_texture(game->mlx_ptr, &game->tex_s);
	free_texture(game->mlx_ptr, &game->tex_e);
	free_texture(game->mlx_ptr, &game->tex_w);
}

void	ft_clean(t_game	*game)
{
	if (game->cub->op_fd > 0)
		close(game->cub->op_fd);
	if (game->status == PARSE)
		ft_free_all(game);	
	else if (game->status == GAME)
	{
		ft_free_all_tex(game);
		if (game->tex && game->tex->img)
			mlx_destroy_image(game->mlx_ptr, game->tex->img);
		ft_free_all(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			free(game->mlx_ptr);
	}
}

