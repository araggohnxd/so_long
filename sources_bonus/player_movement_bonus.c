/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:45:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/28 02:35:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_move_player_up(t_data *data)
{
	char	c;

	c = data->map[data->player_y - 1][data->player_x];
	if (c == '1')
		return (FALSE);
	else if (c == 'C')
		data->collected++;
	else if (c == 'E' || c == 'O')
		return (ft_end_game(data));
	else if (c == 'V' || c == 'H')
		return (ft_kill_player(data));
	data->map[data->player_y][data->player_x] = '0';
	data->map[--(data->player_y)][data->player_x] = 'W';
	return (TRUE);
}

static int	ft_move_player_left(t_data *data)
{
	char	c;

	c = data->map[data->player_y][data->player_x - 1];
	if (c == '1')
		return (FALSE);
	else if (c == 'C')
		data->collected++;
	else if (c == 'E' || c == 'O')
		return (ft_end_game(data));
	else if (c == 'V' || c == 'H')
		return (ft_kill_player(data));
	data->map[data->player_y][data->player_x] = '0';
	data->map[data->player_y][--(data->player_x)] = 'A';
	return (TRUE);
}

static int	ft_move_player_down(t_data *data)
{
	char	c;

	c = data->map[data->player_y + 1][data->player_x];
	if (c == '1')
		return (FALSE);
	else if (c == 'C')
		data->collected++;
	else if (c == 'E' || c == 'O')
		return (ft_end_game(data));
	else if (c == 'V' || c == 'H')
		return (ft_kill_player(data));
	data->map[data->player_y][data->player_x] = '0';
	data->map[++(data->player_y)][data->player_x] = 'S';
	return (TRUE);
}

static int	ft_move_player_right(t_data *data)
{
	char	c;

	c = data->map[data->player_y][data->player_x + 1];
	if (c == '1')
		return (FALSE);
	else if (c == 'C')
		data->collected++;
	else if (c == 'E' || c == 'O')
		return (ft_end_game(data));
	else if (c == 'V' || c == 'H')
		return (ft_kill_player(data));
	data->map[data->player_y][data->player_x] = '0';
	data->map[data->player_y][++(data->player_x)] = 'D';
	return (TRUE);
}

void	ft_move_player(int keysym, t_data *data)
{
	int	player_moved;

	player_moved = 0;
	if (keysym == XK_Up || keysym == XK_w)
		player_moved = ft_move_player_up(data);
	else if (keysym == XK_Left || keysym == XK_a)
		player_moved = ft_move_player_left(data);
	else if (keysym == XK_Down || keysym == XK_s)
		player_moved = ft_move_player_down(data);
	else if (keysym == XK_Right || keysym == XK_d)
		player_moved = ft_move_player_right(data);
	if (player_moved)
		ft_printf(CYAN CLEAR"Moves: %d\n"RESET, ++(data->moves));
}
