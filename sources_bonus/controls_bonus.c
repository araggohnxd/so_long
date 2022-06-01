/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:06:43 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/01 18:42:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_entity(char *from, char *to, char old_char, char new_char)
{
	*from = old_char;
	*to = new_char;
	return (TRUE);
}

int	ft_kill_player(t_data *data)
{
	data->map[data->player_y][data->player_x] = 'R';
	data->end_game = 1;
	data->dead_player = 1;
	return (TRUE);
}

int	ft_end_game(t_data *data, char key)
{
	if (data->collected == data->c_count)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->end_game = 1;
		return (TRUE);
	}
	data->map[data->player_y][data->player_x] = key;
	return (FALSE);
}

int	ft_close_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.floor);
	mlx_destroy_image(data->mlx_ptr, data->image.wall);
	mlx_destroy_image(data->mlx_ptr, data->image.collect);
	mlx_destroy_image(data->mlx_ptr, data->image.exit_close);
	mlx_destroy_image(data->mlx_ptr, data->image.exit_open);
	mlx_destroy_image(data->mlx_ptr, data->image.player_w);
	mlx_destroy_image(data->mlx_ptr, data->image.player_a);
	mlx_destroy_image(data->mlx_ptr, data->image.player_s);
	mlx_destroy_image(data->mlx_ptr, data->image.player_d);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1a);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2a);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1d);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2d);
	mlx_destroy_image(data->mlx_ptr, data->image.rip);
	mlx_destroy_image(data->mlx_ptr, data->image.counter);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	ft_free_split(data->map);
	exit(MLX_SUCCESS);
	return (0);
}

int	ft_keypress_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_q)
		ft_close_game(data);
	else if (data->end_game)
		return (MLX_ERROR);
	else if (keysym == XK_Up || keysym == XK_w
		||keysym == XK_Left || keysym == XK_a
		|| keysym == XK_Down || keysym == XK_s
		|| keysym == XK_Right || keysym == XK_d)
		ft_player_movement(keysym, data);
	return (MLX_SUCCESS);
}
