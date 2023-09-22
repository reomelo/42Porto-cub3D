#include "./includes/cub3D.h"

void	ft_init_structs(t_root *root)
{
	t_tinfo 	*tinfo;
	t_map		*map;
	t_mlx		 *mlx;
	t_player	*player;
	t_ray		*rays;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	rays = malloc(sizeof(t_ray) * SCREEN_WIDTH);

	tinfo->north = NULL;
	tinfo->south = NULL;
	tinfo->east = NULL;
	tinfo->west = NULL;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT	, "Cub3D");
	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
	root->player = player;
	root->rays = rays;
}

int main(int argc, char **argv)
{

	t_root *root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	if (argc != 2)
		return (ft_panic(root));
	if(!ft_initial_validation(argv[1], root))
		return (1);
	ft_render_map(root);
	ft_render_mini_map(root->mlx, root->map);
	mlx_loop(root->mlx->mlx);
	ft_print_info(root);
}