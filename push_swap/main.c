/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/05 04:58:44 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_stk	stack_a;
	s_stk	stack_b;
	int		aux;

	aux = 0;
	stack_a.stk = 0;
	stack_a.stk = compnums(argc, argv, &stack_a);
	stack_b.targ = 0;
	stack_b.stk = malloc(sizeof(int) * stack_b.targ);
	ft_bzero(stack_b.stk, stack_a.targ * sizeof(int));
	stack_a.stk = simp(stack_a);
	primorder(stack_b, stack_a);
	if (stack_a.stk == NULL)
	{
		ft_printf("ERROR guardando los elementos\n");
		return (1);
	}
 	if (comprep(stack_a, stack_a.targ) == 1)
	{
		ft_printf("ERROR números repetidos\n");
		return (1);
	}
	ft_printf("stack A\n");
	while (aux < stack_a.targ)
	{
		printf("%d\n", stack_a.stk[aux]);
		aux++;
	}
	aux = 0;
/* 	ft_printf("stack B\n");
	while (aux < stack_a.targ)
	{
		printf("%d\n", stack_b.stk[aux]);
		aux++;
	}
	ft_printf("t es %d en b\n", stack_b.targ); */
	//proteger mallocs
	free(stack_a.stk);
	free(stack_b.stk);
	return (0);
}
