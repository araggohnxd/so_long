/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:45:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/31 20:50:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_enemy_toupper(t_data *data)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = &data->map[i][j];
			if (ft_strchr(ENEMY_CHARS_L, *c))
				*c = ft_toupper(*c);
			++j;
		}
		++i;
	}
}

static void	ft_switch_enemy_dir(char *key)
{
	if (*key == 'H')
		*key = 'j';
	else if (*key == 'J')
		*key = 'h';
	else if (*key == 'F')
		*key = 'v';
	else if (*key == 'V')
		*key = 'f';
}

static void	ft_move_enemy(t_data *data, char *key, int x, int y)
{
	if (*key == 'H' && data->map[y][x - 1] == '0')
		ft_move_entity(key, &data->map[y][x - 1], '0', ft_tolower(*key));
	else if (*key == 'H' && ft_strchr(PLAYER_CHARS, data->map[y][x - 1]))
		ft_kill_player(data);
	else if (*key == 'J' && data->map[y][x + 1] == '0')
		ft_move_entity(key, &data->map[y][x + 1], '0', ft_tolower(*key));
	else if (*key == 'J' && ft_strchr(PLAYER_CHARS, data->map[y][x + 1]))
		ft_kill_player(data);
	else if (*key == 'F' && data->map[y - 1][x] == '0')
		ft_move_entity(key, &data->map[y - 1][x], '0', ft_tolower(*key));
	else if (*key == 'F' && ft_strchr(PLAYER_CHARS, data->map[y - 1][x]))
		ft_kill_player(data);
	else if (*key == 'V' && data->map[y + 1][x] == '0')
		ft_move_entity(key, &data->map[y + 1][x], '0', ft_tolower(*key));
	else if (*key == 'V' && ft_strchr(PLAYER_CHARS, data->map[y + 1][x]))
		ft_kill_player(data);
	else
		ft_switch_enemy_dir(key);
}

void	ft_enemy_movement(t_data *data)
{
	int		i;
	int		j;
	char	*c;

	if (++(data->loop_tick) < 10 || data->end_game)
		return ;
	data->loop_tick = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = &data->map[i][j];
			if (ft_strchr(ENEMY_CHARS, *c))
				ft_move_enemy(data, c, j, i);
			++j;
		}
		++i;
	}
	ft_enemy_toupper(data);
}
