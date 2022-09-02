/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:02:01 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/02 16:09:19 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_game	game;

	init_struct(&game);
	read_map(&game);
	if (game.map == NULL)
		return (-1);
	if (!valid_map(&game))
	{
		write(1, "Invalid map!\n", 13);
		free_map(&game);
		return (-1);
	}
	init_game(&game);
	map_set(&game);
	mlx_key_hook(game.win, keyhook, &game);
	mlx_loop(game.mlx);
}
