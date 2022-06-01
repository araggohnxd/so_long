/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:30:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/01 20:31:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_images(t_data *data)
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
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1i);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1j);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1k);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_1l);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2i);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2j);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2k);
	mlx_destroy_image(data->mlx_ptr, data->image.enemy_2l);
	mlx_destroy_image(data->mlx_ptr, data->image.rip);
	mlx_destroy_image(data->mlx_ptr, data->image.counter);
}
