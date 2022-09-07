/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:51:38 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/07 09:01:15 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *file)
{
	char	*temp;
	char	buff[11];
	int		n;
	int		fd;

	temp = NULL;
	fd = open(file, O_RDONLY);
	while (1)
	{
		n = read(fd, buff, 10);
		if (n <= 0)
			break ;
		buff[n] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	game->map = ft_split(temp, '\n');
	free(temp);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	valid_wall(char *map, int option, int len)
{
	int	i;

	i = 0;
	if (option == 0)
	{
		while (map[i])
		{
			if (map[i] != '1')
				return (0);
			i++;
		}
	}
	else
	{
		if (map[0] != '1' || map[len - 1] != '1')
			return (0);
	}
	return (1);
}

void	cnt_game(t_game *game, char *map, int col)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			game->exit++;
		else if (map[i] == 'C')
			game->collect++;
		else if (map[i] == 'P')
		{
			game->p_col = col;
			game->p_row = i;
			game->player++;
		}
		i++;
	}
}

int	valid_map(t_game *game)
{
	int	i;

	i = 0;
	game->m_row = ft_strlen(game->map[0]);
	if (!valid_wall(game->map[0], 0, game->m_row))
		return (0);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->m_row)
			return (0);
		if (!valid_wall((game->map[i]), 1, game->m_row))
			return (0);
		cnt_game(game, game->map[i], i);
		i++;
	}
	if (!valid_wall(game->map[i - 1], 0, game->m_row))
		return (0);
	if (!game->collect || !game->exit || !game->player)
		return (0);
	game->m_col = i;
	return (1);
}
