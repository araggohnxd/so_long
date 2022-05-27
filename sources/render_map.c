/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/27 18:51:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sprite(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		image, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

int	ft_render_map(t_data *data)
{
	int	i;
	int	j;

	if (!data->win_ptr)
		return (MLX_ERROR);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				ft_render_sprite(data, data->img_floor, j++, i);
			else if (data->map[i][j] == '1')
				ft_render_sprite(data, data->img_wall, j++, i);
			else if (data->map[i][j] == 'C')
				ft_render_sprite(data, data->img_collect, j++, i);
			else if (data->map[i][j] == 'P')
				ft_render_sprite(data, data->img_player, j++, i);
			else if (data->map[i][j] == 'E')
				ft_render_sprite(data, data->img_exit, j++, i);
		}
		++i;
	}
	return (MLX_SUCCESS);
}
