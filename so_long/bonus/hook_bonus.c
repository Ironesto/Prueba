#include "so_long_bonus.h"

static void erase_coll(t_data *data)
{
	int	i;

	i = 0;
	while (data->pp.y != data->cp[i].y || data->pp.x != data->cp[i].x)
		i++;
	if (i > data->totcol)
	{
		write(2, "Error\n", 6);
		return ;
	}
	data->image.cartucho->instances[i].enabled = false;
	data->totcol--;
	data->map[data->pp.y][data->pp.x] = '0';
}

static void enemcoll_bonus(t_data *data, int i)
{
	//int	i;

	//i = 0;
	//while ((data->pp.y != data->ap[i].y || data->pp.x != data->ap[i].x) && i <= data->image.ale->count)
	//{
		//i++;
		if (data->pp.y == data->ap[i].y && data->pp.x == data->ap[i].x)
			mlx_close_window(data->mlx);
	//}
}

static void	opendoor(t_data *data)
{
	data->image.gabi[0].enabled = false;
	data->image.exit->instances[0].enabled = true;
	data->totcol = 0;
	if (data->totcol == 0 && data->map[data->pp.y][data->pp.x] == 'E')
		mlx_close_window(data->mlx);
}

void	movanim_bonus(t_data *data, int x, int y)
{
	int	ctrlx;
	int	ctrly;

	ctrlx = data->image.fermin->instances[0].x;
	ctrly = data->image.fermin->instances[0].y;
	if (x != ctrlx || y != ctrly)
	{
		data->image.fermin2->enabled = true;
		data->image.fermin->enabled = false;
	}
	else
	{
		data->image.fermin2->enabled = false;
		data->image.fermin->enabled = true;
	}

}

void	hookmov_bonus(t_data *data, int x, int y)
{
	data->image.fermin->instances[0].y += y;
	data->image.fermin2->instances[0].y += y;
	data->image.fermin2->instances[0].x += x;
	data->image.fermin->instances[0].x += x;
}

void	movene_bonus(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->image.ale->count)
	{
		x = data->image.ale2->instances[i].x;
		y = data->image.ale2->instances[i].y;
		if (data->image.ale2->instances[i].x < data->image.fermin->instances[0].x)
			if (compmovx2e_bonus(y, x, 64, data, i) == 0)
				data->image.ale2->instances[i].x++;
		if (data->image.ale2->instances[i].x > data->image.fermin->instances[0].x)
			if (compmovxe_bonus(y, x, 64, data, i) == 0)
				data->image.ale2->instances[i].x--;
		if (data->image.ale2->instances[i].y < data->image.fermin->instances[0].y)
			if (compmovy2e_bonus(y, x, 64, data, i) == 0)
				data->image.ale2->instances[i].y++;
		if (data->image.ale2->instances[i].y > data->image.fermin->instances[0].y)
			if (compmovye_bonus(y, x, 64, data, i) == 0)
				data->image.ale2->instances[i].y--;
		enemcoll_bonus(data, i);
		movanimene_bonus(data, x, y, i);
		i++;
	}
}

void	hook(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = data->image.fermin->instances[0].x;
	y = data->image.fermin->instances[0].y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)  && compmovy(x, y, 64, data) != 1)
		hookmov_bonus(data, 0, -2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && compmovy2(x, y, 64, data) != 1)
		hookmov_bonus(data, 0, 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && compmovx(y, x, 64, data) != 1)
		hookmov_bonus(data, -2, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) && compmovx2(y, x, 64, data) != 1)
		hookmov_bonus(data, 2, 0);
	if (data->map[data->pp.y][data->pp.x] == 'C')
		erase_coll(data);
	if (data->totcol == 1 || data->totcol == 0)
		opendoor(data);
	movanim_bonus(data, x, y);
	movene_bonus(data);
}
