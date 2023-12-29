/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:53:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/28 21:27:36 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_see(t_data *data)
{
	int x = 0;

	x = 0;
	while (x < data->h)
	{
		ft_printf("%s", data->map[x]);
		x++;
	}
	ft_printf("high: %d wight: %d\n", data->h, data->w);
	ft_printf("jugador en: y: %d x: %d\n", data->pp.y, data->pp.x);
	ft_printf("salida en: y: %d x: %d\n", data->ep.y, data->ep.x);
}

void erase_coll(t_data *data)
{
	int	i;

	i = 0;
	//ft_printf("pers x %d, y %d\n",data->pp.x, data->pp.y);
	while (data->pp.y != data->cp[i].y || data->pp.x != data->cp[i].x)
		i++;
	if (i > data->totcol)
	{
		write(2, "Error encontrando el objeto\n",28);
		return ;
	}
	//ft_printf("ins x %d, y %d\n",data->cp[i].x, data->cp[i].y);
	data->image.cartucho->instances[i].enabled = false;
	data->totcol--;
	//ft_printf("instancia %d\n",i);
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && compmovy(data->image.fermin->instances[0].x, data->image.fermin->instances[0].y, 64, data) != 1)
		data->image.fermin->instances[0].y -= 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && compmovy2(data->image.fermin->instances[0].x, data->image.fermin->instances[0].y, 64, data) != 1)
		data->image.fermin->instances[0].y += 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && compmovx(data->image.fermin->instances[0].y, data->image.fermin->instances[0].x, 64, data) != 1)
		data->image.fermin->instances[0].x -= 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && compmovx2(data->image.fermin->instances[0].y, data->image.fermin->instances[0].x, 64, data) != 1)
		data->image.fermin->instances[0].x += 2;
	if (data->map[data->pp.y][data->pp.x] == 'C')
	{
		erase_coll(data);
		data->map[data->pp.y][data->pp.x] = '0';
	}
	if (data->totcol == 1)
	{
		data->image.gabi[0].enabled = false;
		data->image.exit->instances[0].enabled = true;
		data->totcol = 0;
	}
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
	return (NULL);
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
		ft_free(data.map);
		ft_free(data.cpy);
		return (1);
	}
	//ft_printf("w %d h %d\n", data.w, data.h);
	data.mlx = mlx_init((data.w - 1) * size, data.h * size, argv[1], true);
	seeimage(&data);		//proteger imagenes
	puts("seeimage OK");
	createmap(&data, size);
	puts("createmap OK");
	createitem(&data, size);
	puts("createitem OK");
	data.totcol = data.image.cartucho->count + 1;
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free(data.map);
	ft_free(data.cpy);
	free(data.cp);
	return (0);
}

	//ft_printf("Funciona el make\n");