/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/25 05:47:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_images(t_data *data)
{
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/0.xpm",
			&data->map_width, &data->map_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/1.xpm",
			&data->map_width, &data->map_height);
	data->img_collect = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/C.xpm",
			&data->map_width, &data->map_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/P.xpm",
			&data->map_width, &data->map_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/E.xpm",
			&data->map_width, &data->map_height);
}

static int	ft_init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (FALSE);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_width, data->map_height, "so_long");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (FALSE);
	}
	ft_init_images(data);
	mlx_loop_hook(data->mlx_ptr, ft_render, data);
	mlx_key_hook(data->win_ptr, ft_close_game, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (TRUE);
}

static void	ft_init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
}

static char	**ft_get_map(char *map)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	join = ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		join = ft_strjoin_free(join, line);
	}
	split = ft_split(join, '\n');
	free(join);
	close(fd);
	return (split);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		if (argc > 2)
			ft_printf(RED"[ERROR] Too many arguments.\n"RESET);
		else if (argc < 2)
			ft_printf(RED"[ERROR] Map missing.\n"RESET);
		return (1);
	}
	data.map = ft_get_map(argv[1]);
	ft_init_data(&data);
	if (!ft_validate_map(&data))
	{
		ft_printf(RED"[ERROR] Invalid map.\n"RESET);
		return (1);
	}
	ft_init_game(&data);
	ft_free_split(data.map);
	return (0);
}
