#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>

# define MAP "map_file"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SQUARE_SIZE 16
# define FOV 60
# define FLOOR_COLOR 0x00808080
# define CEILING_COLOR 0x005A5A5A
# define ROTATION 10
# define SPEED 0.2
# define PI 3.14159265359 


typedef struct s_tinfo
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		floor[3];
	int		ceil[3];
}				t_tinfo;

typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_data;

typedef struct s_player
{
	double x;
	double y;
	double direction;
	double speed;
	double rotation;
}				t_player;

typedef struct s_ray
{
	double x;
	double y;
	double dis_wall;
	double angle;
}				t_ray;

typedef struct s_map
{
	char **map_arr;
	int n_col;
	int n_lines;
	t_data imgs[3];
}				t_map;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	t_data floor;
	t_data wall;
	t_data map;
}				t_mlx;

typedef struct s_root
{
	t_tinfo 	*tinfo;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_ray		*rays;
}				t_root;


void ft_print_textures(t_tinfo *tinfo);
int ft_panic(t_root *root);
void ft_print_arr(char **arr);
void ft_print_info(t_root *root);
bool ft_add_rgb(char *path, int colors[3]);
bool ft_is_valid_extension(char *str, char *extension);
bool ft_err(char *str, t_root *root);
bool ft_is_valid_file(char *str, t_root *root);
bool ft_is_valid_map(t_map *map, t_player *player);
char *ft_get_trimmed_line(char *line);
bool ft_str_is_map_type(char *str);
bool ft__istinfo_complete(t_tinfo *tinfo);
bool ft_initial_validation(char *str, t_root *root);
bool ft_verify_identifiers(char *str, t_root *root);
bool ft_add_map_file(char *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ft_render_mini_map(t_mlx *mlx, t_map *map);
t_data ft_create_square_img(t_mlx *mlx, int color);
void ft_create_map_images(t_mlx *mlx, t_map *map);
void ft_render_map(t_root *root);
bool is_player(char c);

#endif