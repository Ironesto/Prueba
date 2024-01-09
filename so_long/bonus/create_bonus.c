/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:27:07 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/01/08 20:01:40 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	seeimage_bonus(t_data *data)
{
	mlx_texture_t	*image;

	image = mlx_load_png("./assets/ale.png");
	if (!image)
		return (1);
	data->image.ale = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/ale2.png");
	if (!image)
		return (1);
	data->image.ale2 = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/fermin2.png");
	if (!image)
		return (1);
	data->image.fermin2 = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	return (0);
}

static int	seeimage2(t_data *data)
{
	mlx_texture_t	*image;

	image = mlx_load_png("./assets/gabi.png");
	if (!image)
		return (1);
	data->image.gabi = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/gabi2.png");
	if (!image)
		return (1);
	data->image.exit = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/cartucho.png");
	if (!image)
		return (1);
	data->image.cartucho = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	return (0);
}

int	seeimage(t_data *data)
{
	mlx_texture_t	*image;

	image = mlx_load_png("./assets/wall.png");
	if (!image)
		return (1);
	data->image.wall = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/floor2P.png");
	if (!image)
		return (1);
	data->image.floor = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	image = mlx_load_png("./assets/fermin.png");
	if (!image)
		return (1);
	data->image.fermin = mlx_texture_to_image(data->mlx, image);
	mlx_delete_texture(image);
	if (seeimage2(data)== 1)
		return (1);
	if (seeimage_bonus(data) == 1)
		return (1);
	return (0);
}

void	createmap(t_data *data, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (ft_strchr("0CPEA", data->map[y][x]))
				mlx_image_to_window(data->mlx,
					data->image.floor, x * size, y * size);
			else if (data->map[y][x] == '1')
				mlx_image_to_window(data->mlx,
					data->image.wall, x * size, y * size);
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
	while (y++ < data->h - 1)
	{
		x = 0;
		while (x++ < data->w)
		{
			if (data->map[y][x] == 'C')
				mlx_image_to_window(data->mlx,
					data->image.cartucho, x * size, y * size);
			if (data->map[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx, data->image.exit,
					x * size, y * size);
				data->image.exit->instances[0].enabled = false;
				mlx_image_to_window(data->mlx, data->image.gabi,
					x * size, y * size);
			}
			createitem_bonus(data, x, y, size);
		}
	}
}
