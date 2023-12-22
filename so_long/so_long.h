#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdio.h>

typedef	struct	s_point
{
	int	comp;
	int y;
	int	x;
}	t_point;

typedef struct s_data
{
	char	**map;
	int		h;
	int		w;
	t_point	pp;
	t_point	ep;
	mlx_t	*mlx;
}	t_data;

char	**mapper(char *argv);
int	comp_rect(t_data *data);
int	comp_close(t_data *data);
int	comp_line(t_data *data);
int	comp_item(t_data *data);
int	comp_path(t_data *data, int y, int x);
int	ft_checker(char *argv, t_data *data);

#endif