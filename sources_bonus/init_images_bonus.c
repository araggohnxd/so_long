/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:54:51 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/28 02:33:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init_enemy(t_data *data)
{
	data->image.enemy_1a = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY_1A_XPM,
			&data->map_width, &data->map_height);
	data->image.enemy_2a = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY_2A_XPM,
			&data->map_width, &data->map_height);
	data->image.enemy_1d = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY_1D_XPM,
			&data->map_width, &data->map_height);
	data->image.enemy_2d = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY_2D_XPM,
			&data->map_width, &data->map_height);
}

static void	ft_init_player(t_data *data)
{
	data->image.player_w = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_W_XPM,
			&data->map_width, &data->map_height);
	data->image.player_a = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_A_XPM,
			&data->map_width, &data->map_height);
	data->image.player_s = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_S_XPM,
			&data->map_width, &data->map_height);
	data->image.player_d = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_D_XPM,
			&data->map_width, &data->map_height);
}

static void	ft_init_scenario(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR_XPM,
			&data->map_width, &data->map_height);
	data->image.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_XPM,
			&data->map_width, &data->map_height);
	data->image.collect = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT_XPM,
			&data->map_width, &data->map_height);
	data->image.exit_close = mlx_xpm_file_to_image(data->mlx_ptr, CLOSE_XPM,
			&data->map_width, &data->map_height);
	data->image.exit_open = mlx_xpm_file_to_image(data->mlx_ptr, OPEN_XPM,
			&data->map_width, &data->map_height);
	data->image.rip = mlx_xpm_file_to_image(data->mlx_ptr, RIP_XPM,
			&data->map_width, &data->map_height);
}

void	ft_init_images(t_data *data)
{
	ft_init_scenario(data);
	ft_init_player(data);
	ft_init_enemy(data);
}
