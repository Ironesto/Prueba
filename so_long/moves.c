#include "so_long.h"

int	compmovy(int posx, int pos, int size, t_data *data)
{
	int			aux;
	aux = (pos + 20) / size;

	if (data->map[data->pp.y - 1][data->pp.x] == '1' && aux < data->pp.y)
		return (1);
	if ((pos + 20) / size < data->pp.y && (posx + 47) / size > data->pp.x && data->map[data->pp.y - 1][data->pp.x + 1] == '1' && data->map[data->pp.y][data->pp.x + 1] != '1')
		return (1);
	if ((pos + 20) / size < data->pp.y && (posx + 15) / size < data->pp.x && data->map[data->pp.y - 1][data->pp.x - 1] == '1' && data->map[data->pp.y][data->pp.x - 1] != '1')
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
int	compmovy2(int posx, int pos, int size, t_data *data)
{
	int			aux;

	aux = (pos + 55) / size;
	if ((pos + 63) / size > data->pp.y && data->map[data->pp.y + 1][data->pp.x] == '1')
		return (1);
	if ((pos + 63) / size > data->pp.y && (posx + 47) / size > data->pp.x && data->map[data->pp.y + 1][data->pp.x + 1] == '1' && data->map[data->pp.y][data->pp.x + 1] != '1')
		return (1);
	if ((pos + 63) / size > data->pp.y && (posx + 15) / size < data->pp.x && data->map[data->pp.y + 1][data->pp.x - 1] == '1' && data->map[data->pp.y][data->pp.x - 1] != '1')
		return (1);
	if (aux > data->pp.y && (pos + 20) / size > data->pp.y)
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
int	compmovx2(int posy, int pos, int size, t_data *data)
{
	int			aux;

	aux = (pos + 50) / size;
	if (aux > data->pp.x && data->map[data->pp.y][data->pp.x + 1] == '1')
		return (1);
	if (aux > data->pp.x && (posy + 23) / size < data->pp.y && data->map[data->pp.y - 1][data->pp.x + 1] == '1' && data->map[data->pp.y - 1][data->pp.x] != '1')
		return (1);
	if (aux > data->pp.x && (posy + 61) / size > data->pp.y && data->map[data->pp.y + 1][data->pp.x + 1] == '1' && data->map[data->pp.y + 1][data->pp.x] != '1')
		return (1);
	if ((pos + 20) / size > data->pp.x && aux > data->pp.x)
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

int	compmovx(int posy, int pos, int size, t_data *data)
{
	int	aux;
	aux = (pos + 12) / size;
	if (data->map[data->pp.y][data->pp.x - 1] == '1' && (pos + 12) / size < data->pp.x)
		return (1);
	if (aux < data->pp.x && (posy + 23) / size < data->pp.y && data->map[data->pp.y - 1][data->pp.x - 1] == '1' && data->map[data->pp.y - 1][data->pp.x] != '1')
		return (1);
	if (aux < data->pp.x && (posy + 61) / size > data->pp.y && data->map[data->pp.y + 1][data->pp.x - 1] == '1' && data->map[data->pp.y + 1][data->pp.x] != '1')
		return (1);
	if (aux < data->pp.x && (pos + 40) / size < data->pp.x)
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