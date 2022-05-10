/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 23:18:07 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_printf("%s", "okay til here\n"); // DEBUG
	ft_printf("%s\n", split[0]); // DEBUG
	ft_printf("%s\n", split[1]); // DEBUG
	ft_printf("%s\n", split[2]); // DEBUG
	ft_printf("%s\n", split[3]); // DEBUG
	ft_printf("%s\n", split[4]); // DEBUG
	ft_printf("%s\n", split[5]); // DEBUG
	free(join);
	close(fd);
	return (split);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf(RED"[ERROR] Too many arguments.\n");
		else if (argc < 2)
			ft_printf(RED"[ERROR] Map missing.\n");
		return (0);
	}
	ft_get_map(argv[1]);
	return (0);
}
