/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/25 07:23:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_img_pix_put(t_img *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = image->bpp - 8;
	pixel = image->address + ((y * image->line_len) + (x * (image->bpp / 8)));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_render_sprite(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		image, x * 32, y * 32);
}

int	ft_render(t_data *data)
{
	int	i;
	int	j;

	if (!data->win_ptr)
		return (FALSE);
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
	return (TRUE);
}
