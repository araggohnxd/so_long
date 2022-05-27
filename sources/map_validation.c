/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/27 19:35:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_walls(t_data *data)
{
	int		i;
	int		j;

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

static int	ft_validate_chars(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c_count++;
			else if (data->map[i][j] == 'E')
				data->e_count++;
			else if (data->map[i][j] == 'P')
			{
				data->p_count++;
				data->player_x = j;
				data->player_y = i;
			}
			++j;
		}
	}
	if (data->p_count != 1 || data->e_count != 1 || data->c_count < 1)
		return (FALSE);
	return (TRUE);
}

static int	ft_validate_lines(t_data *data)
{
	size_t	first_len;
	size_t	line_len;
	char	*chars;
	int		i;
	int		j;

	i = 0;
	chars = "01CPE";
	first_len = ft_strlen(data->map[i]);
	data->map_width = first_len;
	while (i < data->map_height)
	{
		j = 0;
		line_len = ft_strlen(data->map[i]);
		while (data->map[i][j])
			if (line_len != first_len || !ft_strchr(chars, data->map[i][j++]))
				return (FALSE);
		++i;
	}
	return (TRUE);
}

static void	ft_init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	data->collected = 0;
	data->moves = 0;
	data->end_game = 0;
}

int	ft_validate_map(t_data *data)
{
	if (!data->map)
		return (FALSE);
	ft_init_data(data);
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
