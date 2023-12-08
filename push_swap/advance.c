/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:30:19 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/08 05:37:04 by gpaez-ga         ###   ########.fr       */
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
	printf("	stack a %d ", temp);
	if (stack_b->num[i].up < stack_b->num[i].down)
		temp += stack_b->num[i].up;
	else
		temp += stack_b->num[i].down;
		printf("stack b %d en i %d	",temp, i);
	return(temp);
}

int	choice(s_stk *stack_a, s_stk *stack_b)
{
	int	i;
	int	temp;
	int	res;

	i = -1;
	res = 0;
	while (i++ < stack_b->targ - 1)
	{
		temp = summov(stack_a, stack_b, i);
		if (summov(stack_a, stack_b, i + 1) > temp)
		{
			temp = summov(stack_a, stack_b, i + 1);
			res = i;
		}
	printf("\nchoice es %d en pos %d", temp, i);
	}
	temp = summov(stack_a, stack_b, i);
	printf("\n\nchoice es %d en pos %d\n", temp, res);
	return (res);
}
