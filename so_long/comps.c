/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:46:07 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/24 03:53:51 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	comp_rect(t_data *data)
{
	int	aux;

	data->h = 0;
	data->w = ft_strlen(data->map[data->h]);
	aux = data->w;
	//ft_see(data);
	while (data->map[data->h])
	{
		if (data->map[data->h] != NULL && data->w != aux)
			return (1);
		data->h++;
		if (data->map[data->h] != NULL)
			data->w = ft_strlen(data->map[data->h]);
	}
	return (0);
}

int	comp_close(t_data *data)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (data->map[0][k] != '\n')
	{
		if (data->map[0][k] != '1')
			return (1);
		k++;
	}
	while (data->map[i])
	{
		if (data->map[i][0] != '1' && data->map[i][data->w - 2] != '1')
			return (1);
		i++;
	}
	k = 0;
	while (data->map[data->h - 1][k] != '\n')
	{
		if (data->map[data->h - 1][k] != '1')
			return (1);
		k++;
	}
	return (0);
}

int	comp_line(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (data->map[i] != NULL)
	{
		k = data->w - 2;
		while (k > 0)
		{
			if (data->map[i][k] != '1' && data->map[i][k] != '0')
				if (data->map[i][k] != 'C' &&
					data->map[i][k] != 'P' && data->map[i][k] != 'E')
					return (1);
			k--;
		}
		i++;
	}
	return (0);
}

static int	save_point(t_data *data, int aux, int k)
{
	if (data->map[aux][k] == 'P')
	{
		data->pp.comp++;
		data->pp.x = k;
		data->pp.y = aux;
	}
	else if (data->map[aux][k] == 'E')
	{
		data->ep.comp++;
		data->ep.x = k;
		data->ep.y = aux;
	}
	if (data->pp.comp > 1 || data->ep.comp > 1)
		return (1);
	return (0);
}

int	comp_item(t_data *data)
{
	int	k;
	int	aux;

	aux = data->h - 1;
	data->pp.comp = 0;
	data->ep.comp = 0;
	while (aux > 0)
	{
		k = 1;
		while (k < data->w - 2)
		{
			if (save_point(data, aux, k) == 1)
				return (1);
			k++;
		}
		aux--;
	}
	if (data->pp.comp == 0 || data->ep.comp == 0)
		return (1);
	return (0);
}
