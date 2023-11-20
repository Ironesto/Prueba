/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/20 20:05:17 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_stk	stack_a;
	int		aux;

	aux = 0;
	stack_a.stk = compnums(argc, argv, &stack_a);
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
	rotate(stack_a.stk, stack_a.targ);
	while (aux < stack_a.targ)
	{
		printf("%d\n", stack_a.stk[aux]);
		aux++;
	}
	free(stack_a.stk);
	return (0);
}
