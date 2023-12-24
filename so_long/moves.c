#include "so_long.h"

int	compmovx2(int pos, int size, t_data *data)
{
	int			aux;

	aux = (pos) / size;
	if (pos < size)
		aux = 1;
	if (aux > data->pp.x)
	{
		if (data->map[data->pp.y][data->pp.x + 1] != '1')
		{
			data->pp.x++;
		}
		else
			return (1);
	}
	return (0);
}

int	compmovy(int pos, int size, t_data *data)
{
	int			aux;
	aux = (pos + 20) / size;

	if (data->map[data->pp.y - 1][data->pp.x] == '1' && aux < data->pp.y)
		return (1);
	if (aux < data->pp.y && (pos + 60) / size < data->pp.y)
	{
		if (data->map[data->pp.y - 1][data->pp.x] != '1')
			data->pp.y--;
		else
			return (1);
	}
	return (0);
}
int	compmovy2(int pos, int size, t_data *data)
{
	int			aux;

	aux = (pos + 63) / size;
	if (aux > data->pp.y)
	{
		if (data->map[data->pp.y + 1][data->pp.x] != '1')
		{
			data->pp.y++;
		}
		else
			return (1);
	}
	return (0);
}

int	compmovx(int pos, int size, t_data *data)
{
	int	aux;
	aux = (pos) / size;
	if (aux < data->pp.x)
	{
		if (data->map[data->pp.y][data->pp.x - 1] != '1')
		{
			data->pp.x--;
		}
		else
			return (1);
	}
	return (0);
}