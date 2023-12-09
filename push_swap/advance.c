/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:30:19 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/09 05:38:02 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	summov(s_stk *stack_a, s_stk *stack_b, int i)
{
	int	temp;

	if (stack_a->num[stack_b->num[i].pair].up < stack_a->num[stack_b->num[i].pair].down)
		temp = stack_a->num[stack_b->num[i].pair].up;
	else
		temp = stack_a->num[stack_b->num[i].pair].down;
	if (stack_b->num[i].up < stack_b->num[i].down)
		temp += stack_b->num[i].up;
	else
		temp += stack_b->num[i].down;
	return(temp);
}

int	choice(s_stk *stack_a, s_stk *stack_b)
{
	int	i;
	int	temp;
	int	res;
	int	temp2;

	i = -1;
	res = 0;
 	while (i++ < stack_b->targ - 1)
	{
		temp2 = summov(stack_a, stack_b, i);
		if (temp2 < temp && i + 1 < stack_b->targ)
		{
			temp = temp2;
			res = i;
		}
	}
	return (res);
}
void	push_swap(s_stk *stack_a, s_stk *stack_b)
{
	int	i;
	int	mova;
	int	movb;

		position(stack_b);
		position(stack_a);
		findpair(stack_a, stack_b);
		i = choice(stack_a, stack_b);
		if (stack_b->num[i].up > stack_b->num[i].down)
			movb = -stack_b->num[i].down;
		else
			movb = stack_b->num[i].up;
		if (stack_a->num[stack_b->num[i].pair].up > stack_a->num[stack_b->num[i].pair].down)
			mova = -stack_a->num[stack_b->num[i].pair].down;
		else
			mova = stack_a->num[stack_b->num[i].pair].up;
		if (movb == 0 && mova == 0)
			{
				push(stack_a, stack_b);}
		else if	(movb > 0 && mova > 0)
		{
			rotinv(stack_a);
			rotinv(stack_b);
		}
		else if (movb < 0 && mova < 0)
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else if (movb > 0 && mova == 0)
			rotate(stack_b);
		else if (movb < 0 && mova == 0)
			{
				rotinv(stack_b);
				}
		else if (mova > 0 && movb == 0)
			rotate(stack_a);
		else if (mova < 0 && movb == 0)
			rotinv(stack_a);
		if ( stack_b->targ > 0)
			push_swap(stack_a, stack_b);
}
