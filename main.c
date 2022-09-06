/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:02:01 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/07 08:28:45 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (-1);
	init_struct(&game);
	read_map(&game, argv[1]);
	if (game.map == NULL)
		return (-1);
	if (!valid_map(&game))
	{
		write(1, "Error Invalid map!\n", 20);
		free_map(&game);
		return (-1);
	}
	init_game(&game);
	map_set(&game);
	mlx_key_hook(game.win, keyhook, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_program, &game);
	mlx_loop(game.mlx);
}
