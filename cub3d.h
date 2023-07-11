/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:05:24 by dayan             #+#    #+#             */
/*   Updated: 2023/05/12 17:05:24 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line.h"

# define MAPWIDTH 10
# define MAPHEIGHT 10
# define GAMEWIDTH 600
# define GAMEHEIGHT 600

typedef enum e_keys
{
	Key_W = 13,
	Key_A = 0,
	Key_S = 1,
	Key_D = 2,
	Key_ESC = 53,
	key_up = 126,
	key_dn = 125,
	key_lt = 123,
	key_rt = 124
}	t_keys;

typedef enum e_map_xpm
{
	xpm = 4,
	int_map = 2,
	map = 1
}	t_map_xpm;

typedef enum e_side
{
	north,
	south,
	west,
	east,
	door
}	t_side;

typedef enum s_floor_ceiling
{
	ft_ceiling,
	ft_floor
}	t_floor_ceiling;

typedef struct s_control
{
	int	read_file;
	int	check_wall;
	int	get_map;
	int	set_map;
	int	player_pos;
}	t_control;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_location
{
	int				x;
	int				y;
}	t_location;

typedef struct s_ray_data
{
	t_vector	ray_location;
	t_location	last_location;
	t_location	wall_location;
	t_vector	for_wall;

}	t_ray;

typedef struct s_xpm
{
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}	t_xpm;

typedef struct s_imgdata
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}	t_imgdata;

typedef struct s_player
{
	t_vector			pos;
	double				direction;
	double				fov;
}	t_player;

typedef struct s_mapdata
{
	char				**map;
	char				**map_clone;
	char				p_dic;
	t_vector			p_start;
	int					map_height;
	int					map_width;
	char				*xpm_dir[5];
	int					colors[2][3];
	int					map_start;
	int					map_end;
	int					**int_map;
}	t_mapdata;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	t_player		player;
	t_xpm			xpm[5];
	t_mapdata		map_data;
	int				width;
	int				height;
	int				dray;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	double			dist_l;
	double			dist_r;
}	t_data;

int					key_press_func(int keycode, t_data *data);
t_ray				calculate_ray(t_data *data, double angle);
void				draw_outlines(t_data *data);
void				draw_square(t_imgdata *img, int x_y[2], \
int size, int color);
void				ft_my_put_pixel(t_imgdata *img_data, int x, int y,
						int color);
unsigned int		ft_my_get_pixel(t_data *data, int x, int y, int i);
void				render_window(t_data *data);
double				deg2rad(int deg);
int					read_file(t_data *data, int fd);
char				*last_trim(char *str);
int					ft_check_rgb(char *s, char **find, int size, t_data *data);
char				*ft_is_space(char *s);
void				array_cleaner(void **arr);
int					ft_check_rgb_2(char *s);
int					color_bitwise(int r, int g, int b);
int					check_null(t_data *data);
int					ft_get_map(t_data *data, char *path);
int					array_len(char **str);
int					longest_line(t_data *data);
int					top_wall(t_data *data);
int					bottom_wall(t_data *data);
int					left_wall(t_data *data);
int					ft_exit(t_data *data);
int					draw_walls(t_data *data, t_ray *ray_data,
						double distance);
int					error_check(t_data *data, char *path);
t_control			ft_recontrol(t_control control);
int					extension_check(char *path);
void				ft_xpm_cleaner(t_data *data);
void				free_func(t_data *data, int control_data);
int					array_len(char **str);
void				render_window(t_data *data);
void				free_int(t_data *data, int **arr);
void				init_color(t_data *data);
void				init_var(t_data *data, char *path);
void				init_xpm(t_data *data);
int					init_direction(t_data *data, int i, int j);
int					get_map_height(char *path);
int					put_map(t_data *data, char **lines);
int					check_wall(t_data *data);
int					check_all_way(t_data *data, int i, int j);
int					ft_count_line(char *path);
int					ft_multi_map(t_data *data, char **lines);
int					draw_screen4(t_data *data, t_ray *ray_data);
int					check_player_exists(t_data *data);
int					check_wall_xpm(t_data *data);
int					ft_set_map(t_data *data);
int					control(char *tmp, int flags, t_data *data, int i);
int					draw_wall_n_img(int angle, double distance, t_data *data,
						t_ray ray_data);
int					draw_wall_e_img(int angle, double distance, t_data *data,
						t_ray ray_data);
int					draw_wall_w_img(int angle, double distance, t_data *data,
						t_ray ray_data);
int					draw_wall_s_img(int angle, double distance, t_data *data,
						t_ray ray_data);
int					draw_floor(int angle, int i, t_data *data);
int					draw_ceiling(int angle, int i, int start, t_data *data);
void				ft_move(int keycode, t_data *data);
int					error(int ret);
int					draw_door_e(int angle, double distance, t_data *data, \
		t_ray ray_data);
int					draw_door_n(int angle, double distance, t_data *data, \
		t_ray ray_data);
int					draw_door_w(int angle, double distance, t_data *data, \
		t_ray ray_data);
int					draw_door_s(int angle, double distance, t_data *data, \
		t_ray ray_data);
void				forward_func(double distance, t_data *data, \
		t_ray ray_data, char c);
void				draw_minimap(t_data *data);
int					draw_walls_forwarded(t_data *data, t_ray *ray_data, \
double distance, char c);
void				check_around_door(t_data *data, int x, int y);
void				check_door(t_data *data);

#endif
