/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:09:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/31 21:42:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_moves_counter(t_data *data)
{
	data->map[0][0] = 'M';
	data->map[0][1] = 'M';
	data->map[0][2] = 'M';
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		SPRITE_SIZE / 2, SPRITE_SIZE / 2, 0xFFFFFF, "Moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		SPRITE_SIZE * 2, SPRITE_SIZE / 2, 0xFFFFFF, ft_itoa(data->moves));
}
