#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef	struct t_stk
{
	int	*stk;
	char **spt;
} 	s_stk;


void	swap(int *p);
void	push(int *ent, int *out);
void	rotate(int *p);
void	rotinv(int *p);

long	ft_atoli(const char *nptr);
int		ft_isalldigit(char* wrd);

char	**ft_free(char **str);
int		savenums(int argc, char **argv, s_stk stack);
int		*compnums(int argc, char **argv, s_stk stack);
int 	comprep(s_stk stack);

#endif