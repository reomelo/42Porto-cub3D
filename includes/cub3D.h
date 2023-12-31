/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei- <riolivei-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:12:20 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/16 18:20:00 by riolivei-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define FOV 0.60
# define SPEED 0.05
# define ROTATION 0.1745
# define FLOOR_COLOR 0x00808080
# define CEILING_COLOR 0x005A5A5A
# define W_COLOR 0x00FF00A9
# define E_COLOR 0x000074D9
# define N_COLOR 0x00D2FF4B
# define S_COLOR 0x00FF5733
# define TRANSPARENCY 0x00980088
# define MAX 1e30
# define PI 3.14159265359
# define MAP "map_file"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define SQUARE_SIZE 16

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define INCOMPLETE_TEX_OR_COLOR_ERR "incomplete color or texture area"
# define INVALID_TEX_OR_COLOR_ERR "invalid texture or color"
# define INVALID_SPACES_OR_TABS "invalid space or tab"
# define INVALID_MAP "Invalid map"
# define INVALID_EXTENSION "Invalid extension"
# define INVALID_FILE "Invalid file"

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_tinfo
{
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
	int		floor[3];
	int		ceil[3];
	double	wall_x;
	int		tex_x;
	int		tex_y;
}					t_tinfo;

typedef struct s_player
{
	double	x;
	double	y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	angle;
	int		n_players;
}					t_player;

typedef struct s_ray
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dis_x;
	double			delta_dis_y;
	int				step_x;
	int				step_y;
	double			per_wall_dist;
	int				color;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			tex_step;
	double			tex_pos;
	t_data			xpm_img;
	struct s_ray	*next;

}					t_ray;

typedef struct s_map
{
	int		is_map_allocated;
	char	**map_arr;
	int		n_col;
	int		n_lines;
	t_data	imgs[3];
	int		map_x;
	int		map_y;
}					t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	map;
	t_data	mini_map;
}					t_mlx;

typedef struct s_moves
{
	int		w_press;
	int		s_press;
	int		a_press;
	int		d_press;
	int		left_press;
	int		right_press;
}					t_moves;

typedef struct s_root
{
	int			exit_success;
	bool		is_empty_file;
	double		wall_num;
	double		camera_x;
	int			hit_wall;
	char		*error_msg;
	t_tinfo		*tinfo;
	t_ray		*rays;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_moves		*moves;
}					t_root;

int		ft_panic(t_root *root);
bool	ft_add_rgb(char *path, int *arr);
bool	ft_is_valid_extension(char *str, char *extension);
bool	ft_err(char *str, t_root *root);
bool	ft_is_valid_file(char *str, t_root *root);
bool	ft_is_valid_map(t_root *root);
char	*ft_get_trimmed_line(char *line);
bool	ft_str_is_map_type(char *str);
bool	ft_istinfo_complete(t_tinfo *tinfo);
bool	ft_initial_validation(char *str, t_root *root);
bool	ft_verify_identifiers(char *str, t_root *root);
bool	ft_add_map_file(char *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_render_mini_map(t_mlx *mlx, t_map *map, t_player *player,
			t_ray *rays);
t_data	ft_create_square_img(t_mlx *mlx, int color, int size);
void	ft_create_map_image(t_mlx *mlx);
void	ft_create_minimap_images(t_mlx *mlx, t_map *map);
int		ft_render_map(t_root *root);
void	ft_cast_rays(t_root *root);
void	ft_dda_algorithm(t_root *root, t_ray *ray, t_map *map);
void	ft_set_step_and_side_dist(t_ray *ray, t_player *player,
			t_map *map);
void	ft_set_ray_length(t_ray *ray);
void	ft_draw(t_ray *ray, t_root *root, int i);
bool	ft_is_player(char c);
bool	ft_init_player(char c, int x, int y, t_player *player);
void	hooks(t_root *root);
void	is_moving(int key_code, int flag, t_moves *moves);
void	is_rotating(int key_code, int flag, t_moves *moves);
void	print_rays(t_mlx *mlx, t_ray *rays, t_player *player);
void	create_rays(t_root *root);
int		close_program(t_root *root);
bool	ft_is_color_complete(int *color);
void	ft_init_structs(t_root *root);
int		ft_puthexa(unsigned long n, char *base);
int		on_key_press(int key_code, t_root *root);
int		on_key_release(int key_code, t_root *root);
void	ft_movements(t_root *root, t_player *player,
			t_moves *moves);
void	player_movement(t_player *player, int key_code,
			t_root *root);
void	player_rotation(t_player *player, int key_code);
void	ft_fill_and_replace(t_map *map, int i, int *j);
bool	ft_str_is_map_type(char *str);
bool	ft_check_all_sides(t_map *map, int y, int x);
bool	ft_is_valid_map(t_root *root);
bool	ft_check_map(t_map *map, t_player *player);
int		ft_get_pixel(t_data img, int x, int y);
void	ft_init_ray(t_root *root, t_player *player, int i);
bool	ft_valid_identifier(char *id, char *path, t_root *root);
bool	ft_is_text_or_color_filled(char *id, t_tinfo *tinfo);
void	ft_fill_and_replace(t_map *map, int i, int *j);
bool	ft_str_is_map_type(char *str);
bool	ft_check_all_sides(t_map *map, int y, int x);
bool	ft_is_valid_map(t_root *root);
bool	ft_check_map(t_map *map, t_player *player);
bool	ft_add_paths(char *id, char *path, t_tinfo *tinfo, t_mlx *mlx);
bool	ft_read_map_file(t_map *map);
bool	ft_is_valid_extension(char *str, char *extension);
bool	ft_is_color_complete(int *color);
bool	ft_istinfo_complete(t_tinfo *tinfo);
void	set_player_y_axis(t_player *player, double plane_x,
			double dir_y, double angle);
void	set_player_x_axis(t_player *player, double plane_y,
			double dir_x, double angle);
void	get_map_arr(t_map *map, int map_file);
void	ft_panic_is_empty_file(t_root *root);
void	ft_free_rays(t_ray *rays);
void	ft_free_double_arr(char **arr);
void	ft_free_mlx(t_root *root);
void	ft_free_minimap_imgs(t_root *root);
#endif