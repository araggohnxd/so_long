/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/01 20:38:20 by maolivei         ###   ########.fr       */
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
# define BADEXT "Invalid map file extension.\n"
# define ALLOWED_CHARS "01CPEIJKL"
# define PLAYER_CHARS "PWASD"
# define SCENARIO_CHARS "01CEORM"
# define ENEMY_CHARS "IJKL"
# define ENEMY_CHARS_L "ijkl"

// Error handling
# define MLX_SUCCESS 0
# define MLX_ERROR 1
# define STDERR 2

// Sprites
# define SPRITE_SIZE 32
# define ENEMY_SPEED 100
# define FLOOR_XPM "./sprites/0.xpm"
# define WALL_XPM "./sprites/1.xpm"
# define COLLECT_XPM "./sprites/C.xpm"
# define PLAYER_W_XPM "./sprites/P_W.xpm"
# define PLAYER_A_XPM "./sprites/P_A.xpm"
# define PLAYER_S_XPM "./sprites/P_S.xpm"
# define PLAYER_D_XPM "./sprites/P_D.xpm"
# define CLOSE_XPM "./sprites/E_CLOSE.xpm"
# define OPEN_XPM "./sprites/E_OPEN.xpm"
# define ENEMY_1I_XPM "./sprites/X_1_I.xpm"
# define ENEMY_1J_XPM "./sprites/X_1_J.xpm"
# define ENEMY_1K_XPM "./sprites/X_1_K.xpm"
# define ENEMY_1L_XPM "./sprites/X_1_L.xpm"
# define ENEMY_2I_XPM "./sprites/X_2_I.xpm"
# define ENEMY_2J_XPM "./sprites/X_2_J.xpm"
# define ENEMY_2K_XPM "./sprites/X_2_K.xpm"
# define ENEMY_2L_XPM "./sprites/X_2_L.xpm"
# define RIP_XPM "./sprites/RIP.xpm"
# define COUNTER_XPM "./sprites/COUNTER.xpm"

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
	void	*enemy_1i;
	void	*enemy_1j;
	void	*enemy_1k;
	void	*enemy_1l;
	void	*enemy_2i;
	void	*enemy_2j;
	void	*enemy_2k;
	void	*enemy_2l;
	void	*rip;
	void	*counter;
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
	int		dead_player;
	int		loop_tick;
	int		player_moved;
}	t_data;

void	ft_check_errors(int argc, char *argv[]);
int		ft_validate_map(t_data *data);
void	ft_render_map(t_data *data);
int		ft_keypress_handler(int keysym, t_data *data);
int		ft_close_game(t_data *data);
int		ft_move_entity(char *from, char *to, char old_char, char new_char);
void	ft_player_movement(int keysym, t_data *data);
void	ft_enemy_movement(t_data *data);
int		ft_end_game(t_data *data, char key);
void	ft_init_images(t_data *data);
int		ft_kill_player(t_data *data);
void	ft_moves_counter(t_data *data);
void	ft_render_sprite(t_data *data, void *image, int x, int y);
void	ft_destroy_images(t_data *data);

#endif /* SO_LONG_BONUS_H */
