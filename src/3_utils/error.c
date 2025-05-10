#include "../include/cub3D.h"

void	ft_error(char *str)
{
	ft_putstr_fd(RED "ERROR:", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" RESET, 2);
}

void	ft_error_close(t_game *game, char *str)
{
	ft_error(str);
	ft_close(game);
}
