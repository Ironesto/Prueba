/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/22 01:50:36 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q 'push_swap'");
}

void	ft_see(t_stk stack_a, t_stk stack_b)
{
	int	aux;

	aux = 0;
	position(&stack_a);
	ft_printf(" _______________________________________________________________________________\n");
	ft_printf("|\tstack A\t\t\t  |\t\tstack B\t\t\t\t|\n");
	ft_printf("|-------------------------------------------------------------------------------|\n");
	while (aux < stack_a.targ + stack_b.targ)
	{
		printf("|\t%d pos %d up %d down %d\t  |\t%d pos %d up %d down %d parpos %d     \t|\n",
			stack_a.num[aux].nbr, stack_a.num[aux].pos, stack_a.num[aux].up,
			stack_a.num[aux].down, stack_b.num[aux].nbr,
			stack_b.num[aux].pos, stack_b.num[aux].up,
			stack_b.num[aux].down, stack_b.num[aux].pair);
		aux++;
	}
	ft_printf("|_______________________________________________________________________________|\n");
	aux = 0;
	ft_printf("t es %d en a\t\t\t\tt es %d en b\n", stack_a.targ, stack_b.targ);
}

static void	lastorder(t_stk stack_a)
{
	int	aux;

	aux = 0;
	while (stack_a.num[aux].nbr != 0)
		aux++;
	if (stack_a.num[aux].up <= stack_a.num[aux].down)
	{
		while (stack_a.num[aux].up > 0)
		{
			ft_printf("ra\n");
			rotate(&stack_a);
			stack_a.num[aux].up--;
		}
	}
	else if (stack_a.num[aux].up > stack_a.num[aux].down)
	{
		while (stack_a.num[aux].down > 0)
		{
			ft_printf("rra\n");
			rotinv(&stack_a);
			stack_a.num[aux].down--;
		}
	}
}

static int	firstcomp(int argc, char **argv, t_stk *stack_a, t_stk *stack_b)
{
	if (argc == 1)
		return (0);
	if (argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (compnums(argc, argv, stack_a) == 1)
	{
		write(2, "Error\n", 6);
		ft_free(stack_a->spt);
		free(stack_a->num);
		free(stack_b->num);
		return (1);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_stk	stack_a;
	t_stk	stack_b;

	//atexit(ft_leaks);
	if (firstcomp(argc, argv, &stack_a, &stack_b) == 1)
		return (1);
	stack_b.targ = 0;
	stack_b.num = malloc (sizeof(t_num) * stack_a.targ);
	stack_a = simp(&stack_a);
	if (comprep(stack_a, stack_a.targ) == 1)
	{
		write(2, "Error\n", 6);
		free(stack_a.num);
		free(stack_b.num);
		return (1);
	}
	primorder(&stack_b, &stack_a);
	while (stack_b.targ > 0)
		push_swap(&stack_a, &stack_b);
	position(&stack_a);
	findpair(&stack_a, &stack_b);
	lastorder(stack_a);
	free(stack_a.num);
	free(stack_b.num);
	return (0);
}
