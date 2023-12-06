#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct t_num
{
	int	nbr;
	int up;
	int	down;
	int pair;
}	s_num;

typedef	struct t_stk
{
	int	targ;

	s_num *num;
	char **spt;
} 	s_stk;

		//moves.c
void	swap(s_stk *stack);
void	rotate(s_stk *stack);
void	rotinv(s_stk *stack);
void	push(s_stk *ent, s_stk *out);

		//tools.c
long	ft_atoli(const char *nptr);
int		ft_isalldigit(char* wrd);
s_stk	simp(s_stk *stack);

		//basic.c
void	threenums(s_stk *stack);
void	movemid(s_stk *stack_b, s_stk *stack_a);
void	primorder(s_stk *stack_b, s_stk *stack);
void	findpair(s_stk *stk_a, s_stk *stk_b);

		//valid.c
char	**ft_free(char **str);
int		savenums(int argc, char **argv, s_stk *stack);
void	compnums(int argc, char **argv, s_stk *stack);
int 	comprep(s_stk stack, int tot);

#endif