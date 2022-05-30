/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/29 02:11:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

// Text formatting
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define CLEAR "\e[1;1H\e[2J"
# define ERROR "Error\n"
# define MISSMAP "Map missing.\n"
# define MANYARG "Too many arguments.\n"
# define BADMAP "Invalid map.\n"
# define ALLOWED_CHARS "01CPEVH"
# define PLAYER_CHARS "PWASD"
# define SCENARIO_CHARS "01CEOR"
# define ENEMY_CHARS "VH"

// Error handling
# define MLX_SUCCESS 0
# define MLX_ERROR 1
# define STDERR 2

// Sprites
# define SPRITE_SIZE 32
# define FLOOR_XPM "./sprites/0.xpm"
# define WALL_XPM "./sprites/1.xpm"
# define COLLECT_XPM "./sprites/C.xpm"
# define PLAYER_W_XPM "./sprites/P_W.xpm"
# define PLAYER_A_XPM "./sprites/P_A.xpm"
# define PLAYER_S_XPM "./sprites/P_S.xpm"
# define PLAYER_D_XPM "./sprites/P_D.xpm"
# define CLOSE_XPM "./sprites/E_CLOSE.xpm"
# define OPEN_XPM "./sprites/E_OPEN.xpm"
# define ENEMY_1A_XPM "./sprites/X_1_A.xpm"
# define ENEMY_2A_XPM "./sprites/X_2_A.xpm"
# define ENEMY_1D_XPM "./sprites/X_1_D.xpm"
# define ENEMY_2D_XPM "./sprites/X_2_D.xpm"
# define RIP_XPM "./sprites/RIP.xpm"

typedef struct s_img {
	void	*floor;
	void	*wall;
	void	*collect;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*exit_close;
	void	*exit_open;
	void	*enemy_1a;
	void	*enemy_2a;
	void	*enemy_1d;
	void	*enemy_2d;
	void	*rip;
}	t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
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
void	ft_player_movement(int keysym, t_data *data);
int		ft_end_game(t_data *data, char key);
void	ft_init_images(t_data *data);
int		ft_kill_player(t_data *data);

#endif /* SO_LONG_BONUS_H */
