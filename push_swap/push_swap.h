#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct t_num
{
	int	num;
	int	indx;
}	s_num;

typedef	struct t_stk
{
	int	targ;
	int	*stk;
	char **spt;
} 	s_stk;


void	swap(s_stk *stack);
void	rotate(s_stk *stack);
void	rotinv(s_stk *stack);
void	push(s_stk *ent, s_stk *out);

long	ft_atoli(const char *nptr);
int		ft_isalldigit(char* wrd);
int		*simp(s_stk stack);
void	threenums(s_stk *stack);
void	movemid(s_stk stack_b, s_stk stack_a);
void	primorder(s_stk stack_b, s_stk stack);

char	**ft_free(char **str);
int		savenums(int argc, char **argv, s_stk *stack);
int		*compnums(int argc, char **argv, s_stk *stack);
int 	comprep(s_stk stack, int tot);

#endif