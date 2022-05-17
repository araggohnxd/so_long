/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/17 13:18:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PUTS 0
# include <fcntl.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef struct s_chars {
	size_t	c_count;
	size_t	p_count;
	size_t	e_count;
	size_t	i;
	size_t	j;
	char	c;
}	t_chars;

int	ft_validate_map(char **map);

#endif /* SO_LONG_H */
