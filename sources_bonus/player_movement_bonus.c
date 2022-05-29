/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:45:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/29 02:02:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_player(char key, t_data *data)
{
	data->map[data->player_y][data->player_x] = '0';
	if (key == 'W')
		data->map[--(data->player_y)][data->player_x] = 'W';
	else if (key == 'A')
		data->map[data->player_y][--(data->player_x)] = 'A';
	else if (key == 'S')
		data->map[++(data->player_y)][data->player_x] = 'S';
	else if (key == 'D')
		data->map[data->player_y][++(data->player_x)] = 'D';
}

static int	ft_check_mov(char key, t_data *data, char *c)
{
	if (*c == '1')
		return (FALSE);
	else if (*c == 'C')
		data->collected++;
	else if (*c == 'E' || *c == 'O')
		return (ft_end_game(data));
	else if (*c == 'V' || *c == 'H')
		return (ft_kill_player(data));
	ft_move_player(key, data);
	return (TRUE);
}

void	ft_player_movement(int keysym, t_data *data)
{
	int	player_moved;

	player_moved = 0;
	if (keysym == XK_Up || keysym == XK_w)
		player_moved = ft_check_mov(
				'W', data, &data->map[data->player_y - 1][data->player_x]);
	else if (keysym == XK_Left || keysym == XK_a)
		player_moved = ft_check_mov(
				'A', data, &data->map[data->player_y][data->player_x - 1]);
	else if (keysym == XK_Down || keysym == XK_s)
		player_moved = ft_check_mov(
				'S', data, &data->map[data->player_y + 1][data->player_x]);
	else if (keysym == XK_Right || keysym == XK_d)
		player_moved = ft_check_mov(
				'D', data, &data->map[data->player_y][data->player_x + 1]);
	if (player_moved)
		ft_printf(CYAN CLEAR"Moves: %d\n"RESET, ++(data->moves));
}
