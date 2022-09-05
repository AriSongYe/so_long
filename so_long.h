/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:53:43 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/05 09:16:04 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
#define P 128

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "./libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*i_1;
	void	*i_2;
	void	*i_3;
	void	*i_4;
	void	*i_5;
	char	**map;
	int		collect;
	int		exit;
	int		player;
	int		m_col;
	int		m_row;
	int		p_col;
	int		p_row;
	int		move_cnt;
}	t_game;

void	read_map(t_game *game);
void	free_map(t_game *game);
void	cnt_game(t_game *game, char *map, int col);
int		valid_wall(char *map, int option, int len);
int		valid_map(t_game *game);
void	init_game(t_game *game);
void	init_struct(t_game *game);
void	map_set(t_game *game);
void	put_image_to_window(int i, int j, t_game *game);
int		keyhook(int keycode, t_game *game);
int		mousehook(int button, int x, int y, t_game *game);
void	move_p(t_game *game, int vertical, int horizon);
void	depart_p(t_game *game, char remain);
void	arrive_p(t_game *game, int vertical, int horizon);


#endif
