/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:53:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/07 05:20:35 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapper(char *argv)
{
	char	**map;
	int		fd;
	int		i;
	int		k;

	k = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	map = malloc(sizeof(char *) * i);
	fd = open(argv, O_RDONLY);
	while (k < i)
	{
		map[k] = get_next_line(fd);
		k++;
	}
	map[k] = NULL;
	close(fd);
	return (map);
}

int	comp_path(t_data *data, int y, int x)
{
	if (ft_strchr("0CE", data->map[y][x]))
		data->map[y][x] = '2';
	if (ft_strchr("0CE", data->map[y - 1][x]) && y - 1 >= 0)
		comp_path(data, y - 1, x);
	if (ft_strchr("0CE", data->map[y + 1][x]) && y + 1 < data->h - 1)
		comp_path(data, y + 1, x);
	if (ft_strchr("0CE", data->map[y][x - 1]) && x - 1 >= 0)
		comp_path(data, y, x - 1);
	if (ft_strchr("0CE", data->map[y][x + 1]) && x + 1 < data->w - 1)
		comp_path(data, y, x + 1);
	if(data->map[data->ep.y][data->ep.x] == '2')
		return (0);
	return (1);
}

int	ft_checker(char *argv, t_data *data)
{
	int		x;

	data->map = mapper(argv);
	if (comp_rect(data) == 1)
		return (1);
	if (comp_close(data) == 1)
		return (1);
	if (comp_line(data) == 1)
		return (1);
	if (comp_item(data) == 1)
		return (1);
	if (comp_path(data, data->pp.y, data->pp.x) == 1)
		return (1);
	x = 0;
	while (x < data->h)
	{
		ft_printf("%s", data->map[x]);
		x++;
	}
	ft_printf("high: %d wight: %d\n", data->h, data->w);
	ft_printf("jugador en: y: %d x: %d\n", data->pp.y, data->pp.x);
	ft_printf("salida en: y: %d x: %d\n", data->ep.y, data->ep.x);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	if (ft_checker(argv[1], &data) == 1)
		return(1);
	data.mlx = mlx_init(data.w * 64, data.h * 64, argv[1], true);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	//ft_printf("Funciona el make\n");
	return (0);
}
