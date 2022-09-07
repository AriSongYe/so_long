/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:49:53 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/07 13:37:09 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->collect = 0;
	game->exit = 0;
	game->player = 0;
	game->m_col = 0;
	game->m_row = 0;
	game->p_col = 0;
	game->p_row = 0;
	game->move_cnt = 0;
}

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->m_row * P, game->m_col * P, "");
	game->i_1 = mlx_xpm_file_to_image(game->mlx, "./obj/tile.xpm", &w, &h);
	game->i_2 = mlx_xpm_file_to_image(game->mlx, "./obj/wall.xpm", &w, &h);
	game->i_3 = mlx_xpm_file_to_image(game->mlx, "./obj/cha.xpm", &w, &h);
	game->i_4 = mlx_xpm_file_to_image(game->mlx, "./obj/col.xpm", &w, &h);
	game->i_5 = mlx_xpm_file_to_image(game->mlx, "./obj/exit.xpm", &w, &h);
}

void	put_image_to_window(int i, int j, t_game *g)
{
	if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
	else if (g->map[i][j] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
		mlx_put_image_to_window(g->mlx, g->win, g->i_2, P * j, P * i);
	}
	else if (g->map[i][j] != '0' && g->map[i][j] != '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
		if (g->map[i][j] == 'P')
			mlx_put_image_to_window(g->mlx, g->win, g->i_3, P * j, P * i);
		else if (g->map[i][j] == 'C')
			mlx_put_image_to_window(g->mlx, g->win, g->i_4, P * j, P * i);
		else if (g->map[i][j] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->i_5, P * j, P * i);
		else if (g->map[i][j] == 'N')
		{
			mlx_put_image_to_window(g->mlx, g->win, g->i_5, P * j, P * i);
			mlx_put_image_to_window(g->mlx, g->win, g->i_3, P * j, P * i);
		}
	}
}

void	map_set(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->m_col)
	{
		j = 0;
		while (j < game->m_row)
		{
			put_image_to_window(i, j, game);
			j++;
		}
		i++;
	}
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_program(game);
	else if (keycode == 13)
		move_p(game, 1, 0);
	else if (keycode == 0)
		move_p(game, 0, 1);
	else if (keycode == 1)
		move_p(game, -1, 0);
	else if (keycode == 2)
		move_p(game, 0, -1);
	else
		printf("Invalid Key\n");
	return (0);
}
