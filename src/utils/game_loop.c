#include "../../includes/cub3D.h"

/* void	player_movement(t_props *props, bool horizontal, int speed)
{
	void	*current_player;

	if (horizontal)
	{
		if (speed < 0)
			current_player = props->images.player_left;
		else
			current_player = props->images.player_right;
		if (props->map.map[props->player_x][props->player_y + speed] == '1')
			return ;
		props->player_y += speed;
	}
	else
	{
		current_player = props->images.player;
		if (props->map.map[props->player_x + speed][props->player_y] == '1')
			return ;
		props->player_x += speed;
	}
	reload(props, current_player);
}

void	reload(t_props	*props, void *current_player)
{
	check_collison(props);
	count_steps(props);
	mlx_clear_window(props->mlx.mlx_ptr, props->mlx.win_ptr);
	load_tilemap(props);
	mlx_put_image_to_window(props->mlx.mlx_ptr, props->mlx.win_ptr,
		current_player, TILES_SIZE * props->player_y,
		TILES_SIZE * props->player_x);
	mlx_string_put(props->mlx.mlx_ptr, props->mlx.win_ptr,
		TILES_SIZE * props->player_y + 30 - (ft_strlen(ft_itoa(props->steps))),
		TILES_SIZE * props->player_x, -1, ft_itoa(props->steps));
} */

int	on_key_press(int key_code, t_root *root)
{
	(void)root;
	if (key_code == ESC)
		exit(0);
	/* else if (key_code == W)
		player_movement(root, false, -1);
	else if (key_code == A)
		player_movement(root, true, -1);
	else if (key_code == S)
		player_movement(root, false, 1);
	else if (key_code == D)
		player_movement(root, true, 1); */
	return (0);
}

int	close_program(void)
{
	exit(0);
}

void	hooks(t_root *root)
{
	/* mlx_hook(root->mlx->mlx, 2, 1, on_key_press, root); */
	mlx_hook(root->mlx->mlx, 17, (1L << 2), close_program, root);
	mlx_loop(root->mlx->mlx);
}