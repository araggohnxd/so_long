/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/17 21:56:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close_game(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	return (0);
}

static int	ft_no_event(void *data)
{
	(void) data;
	return (0);
}

int	ft_init_game(void)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
		return (FALSE);
	window.win_ptr = mlx_new_window(window.mlx_ptr, 500, 500, "hello world");
	if (!window.win_ptr)
	{
		mlx_destroy_display(window.mlx_ptr);
		free(window.mlx_ptr);
		return (FALSE);
	}
	mlx_loop_hook(window.mlx_ptr, ft_no_event, &window);
	mlx_key_hook(window.win_ptr, ft_close_game, &window);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_display(window.mlx_ptr);
	free(window.mlx_ptr);
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
	join = ft_strdup("");
	while (1)
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
	char	**map;

	if (argc != 2)
	{
		if (argc > 2)
			ft_printf(RED"[ERROR] Too many arguments.\n"RESET);
		else if (argc < 2)
			ft_printf(RED"[ERROR] Map missing.\n"RESET);
		return (0);
	}
	map = ft_get_map(argv[1]);
	if (!ft_validate_map(map))
	{
		ft_printf(RED"[ERROR] Invalid map.\n"RESET);
		return (0);
	}
	ft_free_split(map);
	ft_init_game();
	return (0);
}
