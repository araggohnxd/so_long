/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:45:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/26 23:11:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_player_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == '1')
		return ;
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
		data->collected++;
	else if (data->map[data->player_y - 1][data->player_x] == 'E')
		if (data->collected != data->c_count)
			return ;
	data->map[data->player_y][data->player_x] = '0';
	data->map[--(data->player_y)][data->player_x] = 'P';
}

static void	ft_move_player_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == '1')
		return ;
	else if (data->map[data->player_y][data->player_x - 1] == 'C')
		data->collected++;
	else if (data->map[data->player_y][data->player_x - 1] == 'E')
		if (data->collected != data->c_count)
			return ;
	data->map[data->player_y][data->player_x] = '0';
	data->map[data->player_y][--(data->player_x)] = 'P';
}

static void	ft_move_player_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == '1')
		return ;
	else if (data->map[data->player_y + 1][data->player_x] == 'C')
		data->collected++;
	else if (data->map[data->player_y + 1][data->player_x] == 'E')
		if (data->collected != data->c_count)
			return ;
	data->map[data->player_y][data->player_x] = '0';
	data->map[++(data->player_y)][data->player_x] = 'P';
}

static void	ft_move_player_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '1')
		return ;
	else if (data->map[data->player_y][data->player_x + 1] == 'C')
		data->collected++;
	else if (data->map[data->player_y][data->player_x + 1] == 'E')
		if (data->collected != data->c_count)
			return ;
	data->map[data->player_y][data->player_x] = '0';
	data->map[data->player_y][++(data->player_x)] = 'P';
}

void	ft_move_player(int keysym, t_data *data)
{
	if (keysym == XK_Up || keysym == XK_w)
		ft_move_player_up(data);
	else if (keysym == XK_Left || keysym == XK_a)
		ft_move_player_left(data);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_move_player_down(data);
	else if (keysym == XK_Right || keysym == XK_d)
		ft_move_player_right(data);
}
