/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:32 by lifan             #+#    #+#             */
/*   Updated: 2025/05/27 11:56:29 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->head = NULL;
	game->status = PARSE;
	game->height = HEIGHT;
	game->width = WIDTH;
	ft_init_config(game);
	ft_init_map(game->map);
	ft_init_tex(game->tex);
	ft_init_player(game->player);
}

int	ft_not_cub(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ft_memcmp(&file[i], ".cub", 4))
		return (FAIL);
	retrun (0);
}

//* check if the args are valides.
int	ft_check_args(int ac, char **av)
{
	if (ac <= 1)
		return (ft_error("There is no argument."), 1);
	else if (ac > 2)
		return (ft_error("There are too many arguments."), 1);
	else if (ft_not_cub(av[1]))
		return (ft_error("It's not a .cub file."), 1);
	return (0);
}

//* react to keypress and close
//* refresh every loop and stay in the loop.
int	main(int ac, char **av)
{
	t_game	game;

	ft_init_game(&game);
	if (ft_check_args(ac, av))
		return (FAIL);
	if (ft_parse(&game, av))
		return (FAIL);
	mlx_hook(game.win_ptr, 17, (1L << 17), ft_close, &game);
	mlx_hook(game.win_ptr, 2, (1L << 0), ft_key, &game);
	mlx_loop_hook(game.mlx_ptr, ft_refresh, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
