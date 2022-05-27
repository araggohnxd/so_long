/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/27 23:41:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_render_sprite(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		image, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	ft_render_player(t_data *data, char key, int x, int y)
{
	if (key == 'W')
		ft_render_sprite(data, data->image.player_w, x, y);
	else if (key == 'A')
		ft_render_sprite(data, data->image.player_a, x, y);
	else if (key == 'S')
		ft_render_sprite(data, data->image.player_s, x, y);
	else if (key == 'D' || key == 'P')
		ft_render_sprite(data, data->image.player_d, x, y);
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
				ft_render_sprite(data, data->image.floor, j++, i);
			else if (data->map[i][j] == '1')
				ft_render_sprite(data, data->image.wall, j++, i);
			else if (data->map[i][j] == 'C')
				ft_render_sprite(data, data->image.collect, j++, i);
			else if (data->map[i][j] == 'E')
				ft_render_sprite(data, data->image.exit_open, j++, i);
			else if (ft_strchr("PWASD", data->map[i][j++]))
				ft_render_player(data, data->map[i][j - 1], j - 1, i);
		}
		++i;
	}
	return (MLX_SUCCESS);
}
