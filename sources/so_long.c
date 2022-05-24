/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/24 20:41:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	ft_init_game(void)
// {
// 	t_data	data;

// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (FALSE);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "hello world");
// 	if (!data.win_ptr)
// 	{
// 		mlx_destroy_display(data.mlx_ptr);
// 		free(data.mlx_ptr);
// 		return (FALSE);
// 	}
// 	data.image.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
// 	data.image.address = mlx_get_data_addr(data.image.img_ptr, &data.image.bpp,
// 			&data.image.line_len, &data.image.endian);
// 	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
// 	mlx_key_hook(data.win_ptr, ft_close_game, &data);
// 	mlx_loop(data.mlx_ptr);
// 	mlx_destroy_display(data.mlx_ptr);
// 	free(data.mlx_ptr);
// 	return (TRUE);
// }

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
	ft_free_split(data.map);
	// ft_init_game();
	return (0);
}
