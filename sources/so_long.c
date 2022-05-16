/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/16 19:31:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_walls(char **map, int map_height)
{
	int	i;
	int	j;

	i = 0;
	--map_height;
	while (map[0][i] && map[map_height][i])
		if (map[0][i] != '1' || map[map_height][i++] != '1')
			return (FALSE);
	--i;
	j = 1;
	while (j <= map_height)
		if (map[j][0] != '1' || map[j++][i] != '1')
			return (FALSE);
	return (TRUE);
}

static int	ft_validate_map(char **map)
{
	int	map_height;

	if (!map)
		return (FALSE);
	map_height = 0;
	while (map[map_height])
		map_height++;
	if (map_height < 3 || !ft_validate_walls(map, map_height))
	{
		ft_free_split(map);
		return (FALSE);
	}
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
	return (0);
}
