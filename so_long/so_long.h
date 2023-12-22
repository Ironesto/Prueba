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

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*ale;
	mlx_image_t	*cartucho;
	mlx_image_t	*fermin;
	mlx_image_t	*Gabi;
}	t_image;

typedef struct s_data
{
	mlx_t	*mlx;
	char	**map;
	char	**cpy;
	int		h;
	int		w;
	t_point	pp;
	t_point	ep;
	t_image	image;
}	t_data;

void	mapper(char *argv, t_data *data);
int		comp_rect(t_data *data);
int		comp_close(t_data *data);
int		comp_line(t_data *data);
int		comp_item(t_data *data);
int		comp_path(t_data *data, int y, int x);
int		ft_checker(char *argv, t_data *data);

void 	seeimage(t_data *data);
void	createmap(t_data *data, int size);
void	createitem(t_data *data, int size);


#endif