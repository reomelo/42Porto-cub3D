#include "../../includes/cub3D.h"

double ft_degrees_to_radians(double degrees)
{
	double radians;

	radians = degrees * (PI / 180);
	return (radians);
}

void ft_init_rays(t_root *root)
{
	int i;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		root->rays[i].dis_wall = -1;
		root->rays[i].angle = root->player->direction - (ft_degrees_to_radians(FOV)/ 2) + (i * (ft_degrees_to_radians(FOV) / SCREEN_WIDTH));
	}
}

u_int32_t	create_trgb(u_int32_t t, u_int32_t r, u_int32_t g, u_int32_t b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	img_to_matrix(t_data *tmp, u_int32_t **texture, int height, int width)
{
	int				x;
	int				y;
	unsigned char	*c;

	if (texture)
	{
		y = -1;
		while (++y < height)
		{
			x = -1;
			while (++x < width)
			{
				c = (unsigned char *)tmp->addr + (y * tmp->line_length + \
					(x * (tmp->bits_per_pixel / 8)));
				texture[y][x] = create_trgb(c[3], c[2], c[1], c[0]);
			}
		}
	}
}

u_int32_t	**texture_init(void)
{
	u_int32_t	**tex;
	int			y;

	tex = ft_calloc(64 + 1, sizeof(u_int32_t *));
	/* if (!tex)
		error_exit("Failed ft_calloc @texture_init", 1); */
	y = -1;
	while (++y < 64)
	{
		tex[y] = ft_calloc(64, sizeof(u_int32_t));
		/* if (!tex[y])
		{
			error_exit("Failed ft_calloc @texture_init", 1);
		} */
	}
	return (tex);
}


void ft_print_ray(t_root *root, double x, double y, int column)
{
	u_int32_t	**texture;
	int midle = SCREEN_HEIGHT / 2;
	int i;
	int j;
	int t;
	double value1;
	double value2;

	value1 = (x - root->player->x) * (x - root->player->x);
	value2 = (y - root->player->y) * (y - root->player->y);
	root->rays[column].dis_wall = sqrt(value1 + value2);

	texture = texture_init();
	img_to_matrix(root->tinfo->north, texture, 64, 64);
	i = midle - (16 * root->rays[column].dis_wall);
	/* mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->tinfo->north, x*SQUARE_SIZE, y*SQUARE_SIZE); */
	while (i < midle)
	{
		j = -1;
		t = 0;
		while (++j < 16)
			my_mlx_pixel_put(&root->mlx->map, j, column, (int)texture[t][column]);
		i++;
		t++;
	}

	i = midle + (16 * root->rays[column].dis_wall);
	while (i > midle)
	{
		j = -1;
		t = 0;
		while (++j < 16)
			my_mlx_pixel_put(&root->mlx->map, j, column, (int)texture[t][column]);
		i--;
		t++;
	}
}

/* void ft_cast_rays(t_root *root)
{
	int	i;
	double angle_increment;
	double step_x;
	double step_y;
	double ray_x;
	double ray_y;
	bool is_wall;
	
	i = -1;
	is_wall = false;
	angle_increment = ft_degrees_to_radians(FOV) / SCREEN_WIDTH;
	ft_init_rays(root);
	while (++i < SCREEN_WIDTH)
	{
		ray_x = root->player->x;
		ray_y = root->player->y;
		step_x = cos(root->rays[i].angle) * SPEED;
		step_y = sin(root->rays[i].angle) * SPEED;

		while(!is_wall)
		{
			ray_x += step_x;
            ray_y += step_y;
			if(root->map->map_arr[(int)ray_y][(int)ray_x] == '1')
			{
				is_wall = true;
				ft_print_ray(root, ray_x, ray_y, i);
			}
		}
	}
} */

void ft_cast_rays(t_root *root)
{
	double posX = root->player->x, posY = root->player->y;
	double dirX = 1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	double cameraX, rayDirX, rayDirY;
	int x = -1, mapX = (int)posX, mapY = (int)posY;
	double sideDistX, sideDistY;
	double deltaDistX, deltaDistY, perpWallDist;
	int stepX, stepY, side, hit;
	int lineHeight, drawStart, drawEnd;

	while (++x < SCREEN_WIDTH)
	{
		hit = 0;
		cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		deltaDistX = (rayDirX == 0) ? 1e6 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e6 : fabs(1 / rayDirY);

		/* printf("rayDirX: %f\n", rayDirX);
		printf("rayDirY: %f\n", rayDirY); */

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			
			/* printf("sidedistX: %f\n", sideDistX);
			printf("sidedistY: %f\n", sideDistY);
			printf("mapX: %d\n", mapX);
			printf("mapY: %d\n", mapY); */

			if (mapX <= 0 || mapY <= 0 || mapX >= root->map->n_col || mapY >= root->map->n_lines)
				hit = 1;
			else if (root->map->map_arr[mapX][mapY] == '1')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;

		lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;

		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		
		while (drawStart < drawEnd)
		{
            my_mlx_pixel_put(&root->mlx->map, x, drawStart, 0x000000FF);
			drawStart++;
		}
	}
}

void ft_render_map(t_root *root)
{
	int i;
	int j;
	int color;
	t_data map;

	i = -1;
	map.img = mlx_new_image(root->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		if (i < SCREEN_HEIGHT / 2)
			color = CEILING_COLOR;
		else
			color = FLOOR_COLOR;
		while (++j < SCREEN_WIDTH)
            my_mlx_pixel_put(&map, j, i, color);
	}
	root->mlx->map = map;
	ft_cast_rays(root);
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->mlx->map.img, 0, 0);
}