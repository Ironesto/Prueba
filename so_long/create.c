#include "so_long.h"


void seeimage(t_data *data)
{
	mlx_texture_t	*image;

	image = mlx_load_png("./assets/wall.png");
	data->image.wall = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/floor.png");
	data->image.floor = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/Gabi.png");
	data->image.Gabi = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/cartucho.png");
	data->image.cartucho = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/fermin.png");
	data->image.fermin = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
}

void	createmap(t_data *data, int size)
{
	int	x;
	int	y;

	y = 0;

	while(y < data->h)
	{
		x = 0;
		while(x < data->w)
		{
			if(ft_strchr("0CPE", data->map[y][x]))
				mlx_image_to_window(data->mlx, data->image.floor, x * size, y * size);
			else if(data->map[y][x] == '1')
				mlx_image_to_window(data->mlx, data->image.wall, x * size, y * size);
			x++;
		}
		y++;
	}
}

void	createitem(t_data *data, int size)
{
	int	x;
	int	y;

	y = 0;

	while(y < data->h)
	{
		x = 0;
		while(x < data->w)
		{
			if(data->map[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->image.cartucho, x * size, y * size);
			if(data->map[y][x] == 'P')
				mlx_image_to_window(data->mlx, data->image.fermin, x * size, y * size);
			if(data->map[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->image.Gabi, x * size, y * size);
			x++;
		}
		y++;
	}
}
