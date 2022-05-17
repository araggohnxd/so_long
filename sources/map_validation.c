/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/17 13:14:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_chars(char **map, size_t map_height)
{
	t_chars	chars;

	chars.i = 0;
	chars.c_count = 0;
	chars.p_count = 0;
	chars.e_count = 0;
	while (chars.i < map_height)
	{
		chars.j = 0;
		while (map[chars.i][chars.j])
		{
			chars.c = map[chars.i][chars.j];
			if (chars.c == 'C')
				chars.c_count++;
			if (chars.c == 'P')
				chars.p_count++;
			if (chars.c == 'E')
				chars.e_count++;
			++chars.j;
		}
		++chars.i;
	}
	if (chars.p_count != 1 || chars.e_count != 1 || chars.c_count < 1)
		return (FALSE);
	return (TRUE);
}

static int	ft_validate_lines(char **map, size_t map_height)
{
	size_t	first_len;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	first_len = ft_strlen(map[i]);
	while (++i < map_height)
		if (ft_strlen(map[i]) != first_len)
			return (FALSE);
	i = 0;
	while (i < map_height)
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}

static int	ft_validate_walls(char **map, size_t map_height)
{
	size_t	i;
	size_t	j;

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

int	ft_validate_map(char **map)
{
	size_t	map_height;

	if (!map)
		return (FALSE);
	map_height = 0;
	while (map[map_height])
		map_height++;
	if (map_height < 3
		|| !ft_validate_lines(map, map_height)
		|| !ft_validate_chars(map, map_height)
		|| !ft_validate_walls(map, map_height))
	{
		ft_free_split(map);
		return (FALSE);
	}
	return (TRUE);
}
