/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:41:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/21 19:29:45 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
	return (NULL);
}

int	savenums(int argc, char **argv, s_stk *stack)
{
	int	i;
	int	k;
	int	t;

	i = 1;
	t = 0;
	while (i < argc)
	{
		k = 0;
		stack->spt = ft_split(argv[i], ' ');
		while (stack->spt[k])
		{
			stack->stk[t] = ft_atoli(stack->spt[k]);
			if (stack->stk[k] > 2147483647 || stack->stk[k] < -2147483648)
				return (1);
			k++;
			t++;
		}
		ft_free(stack->spt);
		i++;
	}
	return (0);
}

int	*compnums(int argc, char **argv, s_stk *stack)
{
	int		i;
	int		k;
	int		t;

	i = 1;
	t = 0;
	while (i < argc)
	{
		k = 0;
		stack->spt = ft_split(argv[i], ' ');
		while (stack->spt[k])
		{
			if (ft_isalldigit(stack->spt[k]) == 1)
				return (0);
			k++;
			t++;
		}
		ft_free(stack->spt);
		i++;
	}
	stack->targ = t;
	stack->stk = malloc(sizeof(int) * t);
	savenums(argc, argv, stack);
	return (stack->stk);
}

int	comprep(s_stk stack, int tot)
{
	int	i;
	int	k;

	i = 0;
	while (i < tot)
	{
		k = i + 1;
		while (k < tot)
		{
			if (stack.stk[i] == stack.stk[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
