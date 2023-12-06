/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:41:53 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/06 19:55:34 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	threenums(s_stk *stack)
{
	int	zero;
	int	one;
	int	two;

	zero = stack->num[0].nbr;
	one = stack->num[1].nbr;
	two = stack->num[2].nbr;
	if (zero > one && zero > two)
		rotate(stack);
	if (one > zero && one > two)
		rotinv(stack);
	if (two > one && zero < two && one < zero)
		swap(stack);
	if (zero > one || zero > two || one > two)
		threenums(stack);
}

void	movemid(s_stk *stack_b, s_stk *stack_a)
{
	int	tot;
	int	i;

	i = 0;
	tot = stack_a->targ / 2;
	while (i < tot * 2)
	{
		if (stack_a->num[0].nbr > tot)
			push(stack_b, stack_a);
		else
			rotate(stack_a);
		i++;
	}
	while (stack_a->targ > 3)
		push(stack_b, stack_a);
	threenums(stack_a);
}

void	primorder(s_stk *stack_b, s_stk *stack)
{
	int	i;

	if (stack->targ <= 3)
	{
		i = 0;
		while (i < stack->targ && stack->num[i].nbr == i)
			i++;
		if (stack->targ == 2 && i != stack->targ)
			swap(stack);
		if (i == stack->targ)
			return ;
		else
			threenums(stack);
	}
	else
		movemid(stack_b, stack);
	return ;
}

void	findpair(s_stk *stk_a, s_stk *stk_b)
{
	int	i;
	int	j;

	j = 0;
	while (j < stk_b->targ)
	{
		stk_b->num[j].pair = 0;
		i = 0;
		while (i < stk_a->targ)
		{
			if (stk_a->num[i].nbr > stk_b->num[j].nbr)
			{
				stk_b->num[j].pair = stk_a->num[i].nbr;
				i = stk_a->targ;
			}
			i++;
		}
		j++;
	}
}
