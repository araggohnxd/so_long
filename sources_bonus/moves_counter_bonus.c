/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:09:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/01 18:44:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_moves_counter(t_data *data)
{
	char	*moves_str;

	if (!data->moves)
	{
		data->map[0][0] = 'M';
		data->map[0][1] = 'M';
		data->map[0][2] = 'M';
	}
	ft_render_sprite(data, data->image.counter, 0, 0);
	if (data->dead_player)
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			SPRITE_SIZE / 2, SPRITE_SIZE / 2, 0xFF0000, "You died.");
	else if (data->end_game)
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			SPRITE_SIZE / 2, SPRITE_SIZE / 2, 0x00FFFF, "You won!");
	else if (data->player_moved)
	{
		moves_str = ft_itoa(data->moves);
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			SPRITE_SIZE / 2, SPRITE_SIZE / 2, 0xFFFFFF, "Moves:");
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			SPRITE_SIZE * 2, SPRITE_SIZE / 2, 0xFFFFFF, moves_str);
		free(moves_str);
	}
}
