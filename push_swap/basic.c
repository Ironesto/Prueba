#include "push_swap.h"

void	threenums(s_stk *stack)
{
	int	zero;
	int	one;
	int two;

	zero = stack->num[0].nbr;
	one = stack->num[1].nbr;
	two = stack->num[2].nbr;
	if(zero > one && zero > two)
		rotate(stack);
	if(one > zero && one > two)
		rotinv(stack);
	if(two > one && zero < two)
		swap(stack);
	
}

void	movemid(s_stk *stack_b, s_stk *stack_a)
{
	int	tot;

	tot = stack_a->targ / 2;
	while (stack_a->targ > tot && stack_a->targ > 3)
	{
		if (stack_a->num[0].nbr > tot - 1)
			push(stack_b, stack_a);
		else
			rotate(stack_a);
	}
	while (stack_a->targ > 3)
		push(stack_b, stack_a);
	threenums(stack_a);
}

void	primorder(s_stk *stack_b, s_stk *stack)
{
	int	i;

	if(stack->targ <= 3)
	{	
		i = 0;
		while (i < stack->targ && stack->num[i].nbr == i)
			i++;
		if (stack->targ == 2 && i != stack->targ)
			swap(stack);
		if(i == stack->targ)
			return ;
		else
			threenums(stack);
	}
	else
		movemid(stack_b, stack);
	return ;
}

/* void	findpair(s_stk *stk_a, s_stk *stk_b, int i)
{
	int	k;
	k = stk_b->num[i].nbr;
	if (stk_b->num[i].nbr < (stk_a->targ + stk_b->targ) / 2)
		while(k != stk_a->num[].nbr)
} */