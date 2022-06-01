/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/31 21:30:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_loop_hook(t_data *data)
{
	ft_render_map(data);
	ft_moves_counter(data);
	ft_enemy_movement(data);
	++(data->loop_tick);
	return (0);
}

static int	ft_init_game(t_data *data)
{
	data->map_height *= SPRITE_SIZE;
	data->map_width *= SPRITE_SIZE;
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
	mlx_loop_hook(data->mlx_ptr, ft_loop_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, ft_keypress_handler, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, ft_close_game, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
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
		if (*(ft_strrchr(join, '\n') - 1) == '\n')
		{
			free(join);
			return (NULL);
		}
	}
	split = ft_split(join, '\n');
	free(join);
	close(fd);
	return (split);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_check_errors(argc, argv);
	data.map = ft_get_map(argv[1]);
	if (!ft_validate_map(&data))
	{
		ft_putstr_fd(RED ERROR BADMAP RESET, STDERR);
		return (MLX_ERROR);
	}
	ft_init_game(&data);
	return (MLX_SUCCESS);
}
