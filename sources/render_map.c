/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/24 01:49:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
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

void	ft_render_square(t_sqr square, t_img *image)
{
	int	i;
	int	j;

	i = square.y;
	while (i < (square.height + square.y))
	{
		j = square.x;
		while (j < (square.width + square.x))
			ft_img_pix_put(image, j++, i, square.color);
		++i;
	}
}

int	ft_render(t_data *data)
{
	if (!data->win_ptr)
		return (FALSE);
	ft_render_square((t_sqr){10, 10, 100, 100, 0x9681ED}, &data->image);
	mlx_put_image_to_window(
		data->mlx_ptr,
		data->win_ptr,
		data->image.img_ptr,
		0, 0);
	return (TRUE);
}
