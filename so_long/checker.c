#include "so_long.h"

void	mapper(char *argv, t_data *data)
{
	int		fd;
	int		i;
	int		k;

	k = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	data->map = malloc(sizeof(char *) * (i + 1));
	data->cpy = malloc(sizeof(char *) * (i + 1));
	fd = open(argv, O_RDONLY);
	while (k < i)
	{
		data->map[k] = get_next_line(fd);
		data->cpy[k] = ft_strdup(data->map[k]);
		k++;
	}
	data->map[k] = NULL;
	data->cpy[k] = NULL;
	close(fd);
}

int	comp_path(t_data *data, int y, int x)
{
	if (ft_strchr("0CE", data->cpy[y][x]))
		data->cpy[y][x] = '2';
	if (ft_strchr("0CE", data->map[y - 1][x]) && y - 1 >= 0)
		comp_path(data, y - 1, x);
	if (ft_strchr("0CE", data->cpy[y + 1][x]) && y + 1 < data->h - 1)
		comp_path(data, y + 1, x);
	if (ft_strchr("0CE", data->cpy[y][x - 1]) && x - 1 >= 0)
		comp_path(data, y, x - 1);
	if (ft_strchr("0CE", data->cpy[y][x + 1]) && x + 1 < data->w - 1)
		comp_path(data, y, x + 1);
	if (data->cpy[data->ep.y][data->ep.x] == '2')
		return (0);
	return (1);
}

int	ft_checker(char *argv, t_data *data)
{
	mapper(argv, data);
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
	return (0);
}
