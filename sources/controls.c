/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:06:43 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/27 00:28:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_floor);
	mlx_destroy_image(data->mlx_ptr, data->img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	ft_free_split(data->map);
	exit(0);
	return (0);
}

int	ft_keypress_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_q)
		ft_close_game(data);
	else if (keysym == XK_Up || keysym == XK_w
		||keysym == XK_Left || keysym == XK_a
		|| keysym == XK_Down || keysym == XK_s
		|| keysym == XK_Right || keysym == XK_d)
		ft_move_player(keysym, data);
	return (0);
}
