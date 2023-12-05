/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:40:47 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/05 19:12:37 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putnbr_atoi(const char *str, int i)
{
	long	num;

	num = 0;
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		num += (str[i] - '0');
		num *= 10;
		i++;
	}
	num += (str[i] - '0');
	return (num);
}

long	ft_atoli(const char *nptr)
{
	long	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1));
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1) * -1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_putnbr_atoi(nptr, i));
	return (0);
}

int	ft_isalldigit(char *wrd)
{
	int	i;

	i = 0;
	while (wrd[i])
	{
		if (!ft_strchr("+-0123456789", wrd[i]))
			return (1);
		i++;
	}
	return (0);
}

int	*simp(s_stk stack)	//simplifica los numeros dados a 1, 2, 3...
{
	int	i;
	int	k;
	int	indx;

	indx = 0;
	i = 0;
	while (i < stack.targ)
	{
		k = 0;
		while (k < stack.targ)
		{
			if (stack.num[i].nbr > stack.num[i].nbr)
				indx[i] = indx[i] + 1;
			k++;
		}
		i++;
	}
	return(indx);
}
/* int	*simp(s_stk stack)	//simplifica los numeros dados a 1, 2, 3...
{
	int	i;
	int	k;
	int	*indx;
	indx = malloc(sizeof(int) * stack.targ);
	ft_bzero(indx, stack.targ * sizeof(int));
	i = 0;
	while (i < stack.targ)
	{
		k = 0;
		while (k < stack.targ)
		{
			if (stack.stk[i] > stack.stk[k])
				indx[i] = indx[i] + 1;
			k++;
		}
		i++;
	}
	return(indx);
} */

void	threenums(s_stk *stack)
{
	if(stack->stk[0] == 2)
		rotate(stack);
	if(stack->stk[1] == 2)
		rotinv(stack);
	if(stack->stk[2] == 2 && stack->stk[1] == 0)
		swap(stack);
	
}

void	movemid(s_stk *stack_b, s_stk *stack_a)
{
	int	i;
	int	tot;

	i = 0;
	while (i < stack_a->targ)
	{
		if (stack_a->stk[i] > stack_a->targ / 2)
		{
			push(stack_b, stack_a);
			printf("%d  ", tot);
			i = 0;
		}
		i++;
	}
	puts("\n");
}

void	primorder(s_stk *stack_b, s_stk *stack)
{
	int	i;

	if(stack->targ <= 3)
	{	
		i = 0;
		while (i < stack->targ && stack->stk[i] == i)
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
