/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/28 02:39:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_render_sprite(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		image, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	ft_render_enemy(t_data *data, char key, int x, int y)
{
	if (key == 'H' && x % 2 == 0)
		ft_render_sprite(data, data->image.enemy_1a, x, y);
	else if (key == 'H' && x % 2 != 0)
		ft_render_sprite(data, data->image.enemy_2a, x, y);
	else if (key == 'V' && y % 2 == 0)
		ft_render_sprite(data, data->image.enemy_1d, x, y);
	else if (key == 'V' && y % 2 != 0)
		ft_render_sprite(data, data->image.enemy_2d, x, y);
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

static void	ft_render_scenario(t_data *data, char key, int x, int y)
{
	if (key == 'E')
	{
		if (data->collected == data->c_count)
		{
			key = 'O';
			data->map[y][x] = key;
		}
		else
			ft_render_sprite(data, data->image.exit_close, x, y);
	}
	if (key == 'O')
		ft_render_sprite(data, data->image.exit_open, x, y);
	else if (key == '1')
		ft_render_sprite(data, data->image.wall, x, y);
	else if (key == '0')
		ft_render_sprite(data, data->image.floor, x, y);
	else if (key == 'C')
		ft_render_sprite(data, data->image.collect, x, y);
	else if (key == 'R')
		ft_render_sprite(data, data->image.rip, x, y);
}

int	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (ft_strchr(SCENARIO_CHARS, c))
				ft_render_scenario(data, c, j++, i);
			else if (ft_strchr(PLAYER_CHARS, c))
				ft_render_player(data, c, j++, i);
			else if (ft_strchr(ENEMY_CHARS, c))
				ft_render_enemy(data, c, j++, i);
		}
		++i;
	}
	return (MLX_SUCCESS);
}
