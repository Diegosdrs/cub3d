/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:31:13 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/20 13:19:20 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <inttypes.h>
# include <limits.h>
# include <pthread.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "my_library/my_library.h"

# define SCREENW 1280
# define SCREENH 720
# define SIZTEXT 64
# define VITESSE 0.05
# define PI 3.14159265358
# define SENSITIVITY 0.03
# define MOUSESENSE 0.007
# define IS_MAP "NSEW01 "

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}		t_color;

typedef struct s_text
{
	char	*path;
	char	*addr;
	void	*ptr;
	int		bitpp;
	int		len;
	int		endian;
}			t_text;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	cam;
	t_pos		map_square;
	t_vector	ray_dir;
	double		delta_dist_x;
	double		delta_dist_y;
	double		dist_to_side_x;
	double		dist_to_side_y;
	int			step_x;
	int			step_y;
	int			hit_side;
	double		size_ray;
	double		tall_of_wall;
	int			begin_wall;
	int			end_wall;
	int			text_x;
	int			text_y;
	int			mouse;
}			t_player;

typedef struct s_cub
{
	void		*mlx_co;
	void		*window;
	char		**map;
	int			pixel;
	int			map_height;
	int			map_width;
	t_text		nord;
	t_text		sud;
	t_text		est;
	t_text		ouest;
	t_text		frame;
	t_text		minimap;
	t_player	player;
	t_color		ceiling;
	t_color		floor;
	int			escape;
	int			w;
	int			a;
	int			d;
	int			s;
	int			left;
	int			right;
	char		orientation;
}				t_cub;

/******************************************************************************
#                                    ARTHUR                                   *
#*****************************************************************************/

// check_all.c
int				check_all(char **tab);
int				check_input(int ac, char **av);
int				check_order(char **t);

// init_graphics.c
int				init_graphics(t_cub *cub, char **tab);

// utils.c
void			print_double(char **tab);
void			free_double(char **tab);
void			free_double_index(char **s, int index);
char			*ft_strdup_mo(const char *s);
int				is_openable(char *str, int option);

//init_map.c
int				init_map(t_cub *cub, char **tab);

//init_player.c
void			init_player(t_cub *cub, int i, int j, char **tab);

//is_playable.c
int				is_playable(t_cub *cub, char **tab);

/******************************************************************************
#                                    DIEGO                                    *
#*****************************************************************************/

// game.c
int				game_controler(t_cub *cub);
int				display_window(t_cub *cub);
void			init_textures(t_cub *cub, int size);
void			init_frame(t_cub *cub);
void			render_floor_and_ceiling(t_cub *cub, int value);

// game_2.c
int				render_image(t_cub *cub);
int				move_player(t_cub *cub);
int				convert_color(t_cub *cub, int flag);

// game_3.c
unsigned int	rgb_to_hex(int r, int g, int b);
void			render_minimap(t_cub *cub);
void			draw_square(t_cub *cub, int x, int y, int color);

// Algo_raycast
void			algo_raycast(t_cub *cub);
void			map_position(t_player *player);
void			calculate_current_ray(t_cub *cub);
void			calculate_delta(t_cub *cub);
void			dda(t_cub *cub);

// Algo_raycast_2
void			calculate_distance(t_cub *cub);
void			height_wall(t_cub *cub);
void			render_collumn_pixel(t_cub *cub);

// Algo_raycast_utils
t_vector		mult_vector(t_vector *vector, double n);
t_vector		add_vector(t_vector *v1, t_vector *v2);
double			get_distance(t_cub *cub, int zero, int x);
double			perpendicular_dist(t_player *player, int value, int flag);
void			impact_on_wall(t_player *player);

// Algo_raycast_utils_2
void			my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int				obtain_color(t_cub *cub);

// Algo_raycast_utils_3
double			dist_to_wall_x(t_player *player);
double			dist_to_wall_y(t_player *player);
void			rotate_vector(t_vector *v, double angle);

// movement.c
int				movement_key(int key, t_cub *cub);
int				movement_key_2(int key, t_cub *cub);
void			move_up(t_cub *cub);
void			move_down(t_cub *cub);
int				passage(t_cub *cub, double a, double b, int dir);

// movement_2.c
void			move_left(t_cub *cub);
void			move_right(t_cub *cub);
void			turn_left(t_cub *cub);
void			turn_right(t_cub *cub);

// movement_3.c
int				mouse_movement(int x, int y, t_cub *cub);
int				mouse_movement_2(t_cub *cub, double \
rotation_angle, double old_dir_x);
// movement_verif.c
int				verif_passage_nord(t_cub *cub, int y, int x);
int				verif_passage_sud(t_cub *cub, int y, int x);
void			move_dir(t_cub *cub);

// movement_verif_2.c
int				verif_passage_2_1(t_cub *cub, int y, int x);
int				verif_passage_2_2(t_cub *cub, int y, int x);
int				verif_passage_2_3(t_cub *cub, int y, int x);
int				verif_passage_2_4(t_cub *cub, int y, int x);

// Close_game.c
int				close_window(t_cub *cub);
void			free_all(t_cub *cub, int success);
void			free_map(t_cub *cub);

#endif