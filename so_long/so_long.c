/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:46:07 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/06 20:32:59 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

//#include "../MLX42/include/MLX42/MLX42.h"

static char	**mapper(char *argv)
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

static int	comp_rect(char **map)
{
	int	len;
	int	aux;
	int	i;

	i = 1;
	len = ft_strlen(map[0]);
	aux = len;
	while (map[i])
	{
		if (map[i] != NULL && len != aux)
			return (1);
		i++;
		if (map[i] != NULL)
			len = ft_strlen(map[i]);
	}
	return (0);
}

static int	comp_close(char **map, int len, int high)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (map[0][k] != '\n')
	{
		if (map[0][k] != '1')
			return (1);
		k++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][len - 2] != '1')
			return (1);
		i++;
	}
	k = 0;
	while (map[high - 1][k] != '\n')
	{
		if (map[high - 1][k] != '1')
			return (1);
		k++;
	}
	return (0);
}

static int	comp_line(char **map, int len)
{
	int	i;
	int	k;

	i = 0;
	while (map[i] != NULL)
	{
		k = len - 2;
		while (k > 0)
		{
			if (map[i][k] != '1' && map[i][k] != '0')
				if (map[i][k] != 'C' && map[i][k] != 'P' && map[i][k] != 'E')
					return (1);
			k--;
		}
		i++;
	}
	return (0);
}

static int	comp_item(char **map, int len, int high)
{
	int	k;
	int	p;
	int	e;

	p = 0;
	e = 0;
	while (high > 1)
	{
		k = 1;
		while (k < len - 3)
		{
			if (map[high][k] == 'P')
				p++;
			if (map[high][k] == 'E')
				e++;
			k++;
		}
		high--;
	}
	if (e > 1 || p > 1)
		return (1);
	return (0);
}

static int	comp_path(char **map, int high, int len, int x, int y, int *e)
{
	if (map[x][y] == 'E')
		*e = 1;
	if (ft_strchr("0C", map[x][y]))
		map[x][y] = '2';
	if (ft_strchr("0CE", map[x - 1][y]) && x - 1 >= 0)
		comp_path(map, high, len, x - 1, y, e);
	if (ft_strchr("0CE", map[x + 1][y]) && x + 1 < len)
		comp_path(map, high, len, x + 1, y, e);
	if (ft_strchr("0CE", map[x][y - 1]) && y - 1 >= 0)
		comp_path(map, high, len, x, y - 1, e);
	if (ft_strchr("0CE", map[x][y + 1]) && y + 1 < high)
		comp_path(map, high, len, x, y + 1, e);
	if (*e == 1)
		return (0);
	return (1);
}

int	checker(char *argv)
{
	char	**map;
	int		len;
	int		high;
	int		e;
	int		x;

	e = 0;
	map = mapper(argv);
	if (comp_rect(map) == 1)
		return (1);
	len = ft_strlen(map[0]);
	while (map[high])
		high++;
	if (comp_close(map, len, high) == 1)
		return (1);
	if (comp_line(map, len) == 1)
		return (1);
	if (comp_item(map, len, high - 1) == 1)
		return (1);
	if (comp_path(map, len, high, 1, 0, &e) == 1)
		return (1);
	x = 0;
	while (x < high)
	{
		ft_printf("%s", map[x]);
		x++;
	}
	return (0);
}

// comprobar makefile y libft.h para que haga bien el make