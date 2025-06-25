/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:32 by lifan             #+#    #+#             */
/*   Updated: 2025/06/25 16:14:42 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static	int	ft_not_cub(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ft_memcmp(&file[i], ".cub", 4))
		return (FAIL);
	return (0);
}

//* check if the args are valides.
//* check if the path is valide.
static	int	ft_check_args(int ac, char **av)
{
	if (ac <= 1)
		return (ft_error("There is no argument."), 1);
	else if (ac > 2)
		return (ft_error("There are too many arguments."), 1);
	else if (ft_not_cub(av[1]))
		return (ft_error("It's not a .cub file."), 1);
	if (access(av[1], R_OK) != 0)
	{
		ft_error("The file path is invalid.");
		return (FAIL);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ft_check_args(ac, av))
		return (FAIL);
	ft_init_game(&game);
	if (ft_parse(&game, av[1]))
		return (FAIL);
	ft_init_window(&game);
	set_map_size(&game);
	set_player(&game);
	mlx_hook(game.win_ptr, 17, (1L << 17), ft_close, &game);
	mlx_hook(game.win_ptr, 2, (1L << 0), ft_key_press, &game);
	mlx_hook(game.win_ptr, 3, (1L << 1), ft_key_release, &game);
	mlx_loop_hook(game.mlx_ptr, ft_refresh, &game);
	mlx_loop(game.mlx_ptr);
	//ft_debug_parse(&game);
	ft_clean(&game);
	return (0);
}
