/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:29:12 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/01/07 05:28:02 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../MLX42/include/MLX42/MLX42.h"
# include "./../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_point
{
	int	comp;
	int	y;
	int	x;
	int	vect;
}	t_point;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*cartucho;
	mlx_image_t	*fermin;
	mlx_image_t	*gabi;
	mlx_image_t	*exit;
	mlx_image_t	*ale;
	mlx_image_t	*ale2;
	mlx_image_t	*fermin2;
}	t_image;

typedef struct s_data
{
	mlx_t	*mlx;
	char	**map;
	char	**cpy;
	int		h;
	int		w;
	int		moves;
	int		totcol;
	t_point	pp;
	t_point	ep;
	t_point	*cp;
	t_point	*ap;
	t_image	image;
}	t_data;

void	mapper(char *argv, t_data *data);
int		comp_rect(t_data *data);
int		comp_close(t_data *data);
int		comp_line(t_data *data);
int		comp_item(t_data *data);
int		comp_path(t_data *data, int y, int x);
int		ft_checker(char *argv, t_data *data);
void	seeimage(t_data *data);
void	createmap(t_data *data, int size);
void	createitem(t_data *data, int size);
void	hook(void *param);

int		compmovx(int posy, int pos, int size, t_data *data);
int		compmovx2(int posy, int pos, int size, t_data *data);
int		compmovy(int posx, int pos, int size, t_data *data);
int		compmovy2(int posx, int pos, int size, t_data *data);

void	movanimene_bonus(t_data *data, int x, int y, int i);
int		compmovye_bonus(int pos, int posx, int size, t_data *data, int i);
int		compmovy2e_bonus(int pos, int posx, int size, t_data *data, int i);
int		compmovxe_bonus(int posy, int pos, int size, t_data *data, int i);
int		compmovx2e_bonus(int posy, int pos, int size, t_data *data, int i);

void	ft_see(t_data *data);
#endif