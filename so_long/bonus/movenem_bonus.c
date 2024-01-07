#include "so_long_bonus.h"

void	movanimene_bonus(t_data *data, int x, int y, int i)
{
	int	ctrlx;
	int	ctrly;

	ctrlx = data->image.ale2->instances[i].x;
	ctrly = data->image.ale2->instances[i].y;
		if (x != ctrlx || y != ctrly)
		{
			data->image.ale2->instances[i].enabled = true;
			data->image.ale->instances[i].enabled = false;
		}
		else
		{
			data->image.ale2->instances[i].enabled = false;
			data->image.ale->instances[i].enabled = true;
			data->image.ale->instances[i].x = ctrlx;
			data->image.ale->instances[i].y = ctrly;
		}
}

int	compmovye_bonus(int pos, int posx, int size, t_data *data, int i)
{
	int			aux;

	aux = (pos + 20) / size;
	if (data->map[data->ap[i].y - 1][data->ap[i].x] == '1' && aux < data->ap[i].y)
		return (1);
	if ((pos + 20) / size < data->ap[i].y && (posx + 47) / size > data->ap[i].x
		&& data->map[data->ap[i].y - 1][data->ap[i].x + 1] == '1'
			&& data->map[data->ap[i].y][data->ap[i].x + 1] != '1')
		return (1);
	if ((pos + 20) / size < data->ap[i].y && (posx + 15) / size < data->ap[i].x
		&& data->map[data->ap[i].y - 1][data->pp.x - 1] == '1'
			&& data->map[data->ap[i].y][data->pp.x - 1] != '1')
		return (1);
	if (aux < data->ap[i].y && (pos + 60) / size < data->ap[i].y)
	{
		if (!ft_strchr("1AE", data->map[data->ap[i].y - 1][data->ap[i].x]))
		{
			data->map[data->ap[i].y][data->ap[i].x] = '0';
			data->ap[i].y--;
			data->map[data->ap[i].y][data->ap[i].x] = 'A';
		}
		else
			return (1);
	}
	return (0);
}

int	compmovy2e_bonus(int pos, int posx, int size, t_data *data, int i)
{
	int			aux;

	aux = (pos + 55) / size;
	if ((pos + 63) / size > data->ap[i].y
		&& data->map[data->ap[i].y + 1][data->ap[i].x] == '1')
		return (1);
	if ((pos + 63) / size > data->ap[i].y && (posx + 47) / size > data->ap[i].x
		&& data->map[data->ap[i].y + 1][data->ap[i].x + 1] == '1'
			&& data->map[data->ap[i].y][data->ap[i].x + 1] != '1')
		return (1);
	if ((pos + 63) / size > data->ap[i].y && (posx + 15) / size < data->ap[i].x
		&& data->map[data->ap[i].y + 1][data->ap[i].x - 1] == '1'
			&& data->map[data->ap[i].y][data->ap[i].x - 1] != '1')
		return (1);
	if (aux > data->ap[i].y && (pos + 20) / size > data->ap[i].y)
	{
		if (!ft_strchr("1AE", data->map[data->ap[i].y + 1][data->ap[i].x]))
		{
			data->map[data->ap[i].y][data->ap[i].x] = '0';
			data->map[++data->ap[i].y][data->ap[i].x] = 'A';
		}
		else
			return (1);
	}
	return (0);
}

int	compmovxe_bonus(int posy, int pos, int size, t_data *data, int i)
{
	int	aux;

	aux = (pos + 12) / size;
 	if (data->map[data->ap[i].y][data->ap[i].x - 1] == '1'
		&& (pos + 12) / size < data->ap[i].x)
		return (1);
	if (aux < data->ap[i].x && (posy + 23) / size < data->ap[i].y
		&& data->map[data->ap[i].y - 1][data->ap[i].x - 1] == '1'
			&& data->map[data->ap[i].y - 1][data->ap[i].x] != '1')
		return (1);
	if (aux < data->ap[i].x && (posy + 61) / size > data->ap[i].y
		&& data->map[data->ap[i].y + 1][data->ap[i].x - 1] == '1'
			&& data->map[data->ap[i].y + 1][data->ap[i].x] != '1')
		return (1);
	if (aux < data->ap[i].x && (pos + 40) / size < data->ap[i].x)
	{
		if (!ft_strchr("1AE", data->map[data->ap[i].y][data->ap[i].x - 1]))
		{
			data->map[data->ap[i].y][data->ap[i].x] = '0';
			data->map[data->ap[i].y][--data->ap[i].x] = 'A';
		}
		else
			return (1);
	}
	return (0);
}

int	compmovx2e_bonus(int posy, int pos, int size, t_data *data, int i)
{
		int			aux;

	aux = (pos + 50) / size;
	if (aux > data->ap[i].x && data->map[data->ap[i].y][data->ap[i].x + 1] == '1')
		return (1);
	if (aux > data->ap[i].x && (posy + 23) / size < data->ap[i].y
		&& data->map[data->ap[i].y - 1][data->ap[i].x + 1] == '1'
			&& data->map[data->ap[i].y - 1][data->ap[i].x] != '1')
		return (1);
	if (aux > data->ap[i].x && (posy + 61) / size > data->ap[i].y
		&& data->map[data->ap[i].y + 1][data->ap[i].x + 1] == '1'
			&& data->map[data->ap[i].y + 1][data->ap[i].x] != '1')
		return (1);
	if ((pos + 20) / size > data->ap[i].x && aux > data->ap[i].x)
	{
		if (!ft_strchr("1AE", data->map[data->ap[i].y][data->ap[i].x + 1]))
		{
			data->map[data->ap[i].y][data->ap[i].x] = '0';
			data->ap[i].x++;
			data->map[data->ap[i].y][data->ap[i].x] = 'A';
		}
		else
			return (1);
	}
	return (0);
}
