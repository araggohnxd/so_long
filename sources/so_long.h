/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/27 01:33:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

// TESTING PURPOSES
# include <stdio.h>
// TESTING PURPOSES

# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define CLEAR "\e[1;1H\e[2J"
# define SPRITE_SIZE 32

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	char	**map;
	int		map_height;
	int		map_width;
	int		c_count;
	int		p_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
	int		end_game;
}	t_data;

int		ft_validate_map(t_data *data);
int		ft_render_map(t_data *data);
int		ft_keypress_handler(int keysym, t_data *data);
int		ft_close_game(t_data *data);
void	ft_move_player(int keysym, t_data *data);
int		ft_end_game(t_data *data);

#endif /* SO_LONG_H */
