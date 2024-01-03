/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:53:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/01/02 03:07:27 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	so_long(t_data *data, int size)
{
	seeimage(data);
	createmap(data, size);
	createitem(data, size);
	data->totcol = data->image.cartucho->count + 1;
	data->image.ale2->count = data->image.ale->count;
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

void	ft_error(t_data *data)
{
	write(2, "Error\n", 6);
	if (data->map)
		ft_free(data->map);
	if (data->cp)
		free(data->cp);
	if (data->cpy)
		ft_free(data->cpy);
}

void	ft_init_bonus(t_data *data)
{
	data->map = NULL;
	data->cpy = NULL;
	data->cp = NULL;
	data->moves = 0;
	data->pp.comp = 0;
	data->ep.comp = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	//atexit(ft_leaks);
	size = 64;
	ft_init_bonus(&data);
	if (argc != 2 || !argv[0][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_checker(argv[1], &data) == 1)
		return (ft_error(&data), 1);
	ft_free(data.cpy);
	data.mlx = mlx_init((data.w - 1) * size, data.h * size, argv[1], true);
	so_long(&data, size);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free(data.map);
	free(data.cp);
	return (0);
}
