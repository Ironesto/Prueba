/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:53:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/23 20:30:17 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_see(t_data *data)
{
	int x = 0;

	x = 0;
	while (x < 10)
	{
		ft_printf("%s", data->map[x]);
		x++;
	}
	ft_printf("high: %d wight: %d\n", data->h, data->w);
	ft_printf("jugador en: y: %d x: %d\n", data->pp.y, data->pp.x);
	ft_printf("salida en: y: %d x: %d\n", data->ep.y, data->ep.x);
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && compmovy(data->image.fermin->instances[0].y, 64, data) != 1)
		data->image.fermin->instances[0].y -= 3;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && compmovy2(data->image.fermin->instances[0].y, 64, data) != 1)
		data->image.fermin->instances[0].y += 3;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && compmovx(data->image.fermin->instances[0].x, 64, data) != 1)
		data->image.fermin->instances[0].x -= 3;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && compmovx2(data->image.fermin->instances[0].x, 64, data) != 1)
		data->image.fermin->instances[0].x += 3;
	ft_printf("h %d w %d pp y %d x %d\n", data->image.fermin->instances[0].y,
		data->image.fermin->instances[0].x, data->pp.y, data->pp.x);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	size = 64;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_checker(argv[1], &data) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_printf("w %d h %d\n", data.w, data.h);
	data.mlx = mlx_init((data.w - 1) * size, data.h * size, argv[1], true);
	seeimage(&data);
	createmap(&data, size);
	createitem(&data, size);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}

	//ft_printf("Funciona el make\n");