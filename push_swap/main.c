/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/23 19:57:10 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_stk	stack_a;
	s_stk	stack_b;
	int		aux;

	aux = 0;
	stack_a.stk = compnums(argc, argv, &stack_a);
	stack_b.targ = 0;
	stack_b.stk = malloc(sizeof(int) * stack_b.targ);
	ft_bzero(stack_b.stk, stack_a.targ * sizeof(int));
	if (stack_a.stk == 0)
	{
		ft_printf("ERROR guardando los elementos\n");
		return (1);
	}
 	if (comprep(stack_a, stack_a.targ) == 1)
	{
		ft_printf("ERROR números repetidos\n");
		return (1);
	}
	ft_printf("t es %d\n", stack_b.targ);
	push(&stack_b, &stack_a);
	while (aux < stack_a.targ)
	{
		printf("%d\n", stack_b.stk[aux]);
		aux++;
	}
	ft_printf("t es %d\n", stack_b.targ);
	free(stack_a.stk);
	free(stack_b.stk);
	return (0);
}
