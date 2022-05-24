/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/24 20:39:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define HEIGHT 720
# define WIDTH 1280
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

// TESTING PURPOSES
# include <stdio.h>
// TESTING PURPOSES

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef struct s_img {
	void	*img_ptr;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
	char	**map;
	size_t	map_height;
	size_t	map_width;
	size_t	c_count;
	size_t	p_count;
	size_t	e_count;
}	t_data;

int		ft_validate_map(t_data *data);
int		ft_close_game(int keysym, t_data *data);
void	ft_img_pix_put(t_img *image, int x, int y, int color);
int		ft_render(t_data *data);

#endif /* SO_LONG_H */
