/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/07 03:56:36 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_stk	stack_a;
	s_stk	stack_b;
	int		aux;

	aux = 0;
	compnums(argc, argv, &stack_a);
	stack_b.targ = 0;
	stack_b.num = malloc (sizeof(s_num) * stack_a.targ);
	stack_a = simp(&stack_a);
	if (stack_a.num == NULL)
	{
		ft_printf("ERROR guardando los elementos\n");
		return (1);
	}
 	if (comprep(stack_a, stack_a.targ) == 1)
	{
		ft_printf("ERROR números repetidos\n");
		return (1);
	}

	primorder(&stack_b, &stack_a);
	//findpair(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	findpair(&stack_a, &stack_b, 0 , 1);
	findpair(&stack_b, &stack_a, 0 , 1);
	
	ft_printf("stack A\n");
	while (aux < stack_a.targ)
	{
		printf("%d pareja %d\n", stack_a.num[aux].nbr, stack_a.num[aux].pair);
		aux++;
	}
	aux = 0;
	ft_printf("t es %d en a\n", stack_a.targ);
	ft_printf("stack B\n");
	while (aux < stack_b.targ)
	{
		printf("%d pareja %d\n", stack_b.num[aux].nbr, stack_b.num[aux].pair);
		aux++;
	}
	ft_printf("t es %d en b\n", stack_b.targ);
	//proteger mallocs
	return (0);
}
