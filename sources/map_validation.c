/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/24 20:38:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_chars(t_data *data)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c == 'C')
				data->c_count++;
			if (c == 'P')
				data->p_count++;
			if (c == 'E')
				data->e_count++;
			++j;
		}
		++i;
	}
	if (data->p_count != 1 || data->e_count != 1 || data->c_count < 1)
		return (FALSE);
	return (TRUE);
}

static int	ft_validate_lines(t_data *data)
{
	size_t	first_len;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	first_len = ft_strlen(data->map[i]);
	data->map_width = first_len;
	while (++i < data->map_height)
		if (ft_strlen(data->map[i]) != first_len)
			return (FALSE);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}

static int	ft_validate_walls(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[0][i] && data->map[data->map_height - 1][i])
		if (data->map[0][i] != '1'
			|| data->map[data->map_height - 1][i++] != '1')
			return (FALSE);
	--i;
	j = 1;
	while (j <= data->map_height - 1)
		if (data->map[j][0] != '1' || data->map[j++][i] != '1')
			return (FALSE);
	return (TRUE);
}

int	ft_validate_map(t_data *data)
{
	if (!data->map)
		return (FALSE);
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	if (data->map_height < 3
		|| !ft_validate_lines(data)
		|| !ft_validate_chars(data)
		|| !ft_validate_walls(data))
	{
		ft_free_split(data->map);
		return (FALSE);
	}
	return (TRUE);
}
