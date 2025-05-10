#include "../include/cub3D.h"

int free_one(t_game *game, void *ptr)
{
	t_track	*prev;
	t_track	*curr;

	prev =-NULL;
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

void free_all(t_game *game)
{
    t_track *tmp;

    while (game->head)
    {
        tmp = game->head;
        game->head = game->head->next;
        free(tmp->ptr);
        free(tmp);
    }
}



void	ft_close(t_game	*game)
{
	if (game->status == PARSE)
		ft_free_all(game);
	else if (game->status == GAME)
	{
		mlx_destroy_image(game->mlx_ptr, game->tex->img);
		ft_free_all(game);
		if (game->win_ptr)
			mlx_destroy_window((game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	}
	exit (0);
}
