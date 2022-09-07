/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:30:28 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/07 08:59:56 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arrive_p(t_game *game, int vertical, int horizon)
{
	if (game->map[game->p_col - vertical][game->p_row - horizon] == '0')
		game->map[game->p_col - vertical][game->p_row - horizon] = 'P';
	else if (game->map[game->p_col - vertical][game->p_row - horizon] == 'C')
	{
		game->collect--;
		game->map[game->p_col - vertical][game->p_row - horizon] = 'P';
	}
	else if (game->map[game->p_col - vertical][game->p_row - horizon] == 'E')
		game->map[game->p_col - vertical][game->p_row - horizon] = 'N';
}

void	depart_p(t_game *game, char remain)
{
	if (remain == 'N')
		game->map[game->p_col][game->p_row] = 'E';
	else
		game->map[game->p_col][game->p_row] = '0';
}

void	move_p(t_game *game, int vertical, int horizon)
{
	static char	remain;

	if (game->map[game->p_col - vertical][game->p_row - horizon] == '1')
		return ;
	else
	{
		if (game->map[game->p_col - vertical][game->p_row - horizon] == 'E')
		{
			if (game->collect == 0)
			{
				game->move_cnt++;
				printf("move count : %d\n", game->move_cnt);
				exit_program(game);
			}
		}
		arrive_p(game, vertical, horizon);
		depart_p(game, remain);
		remain = game->map[game->p_col - vertical][game->p_row - horizon];
		map_set(game);
		game->p_col -= vertical;
		game->p_row -= horizon;
		game->move_cnt++;
		printf("move count : %d\n", game->move_cnt);
	}
}

int	exit_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
