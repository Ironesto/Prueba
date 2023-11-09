/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:39:58 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/09 17:40:32 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_stk	stack_a;
	int		aux;

	aux = 0;
	stack_a.stk = compnums(argc, argv, stack_a);
	if (stack_a.stk == 0)
	{
		printf("ERROR guardando los elementos\n");
		return (1);
	}
	if (comprep(stack_a) == 1)
	{
		ft_printf("ERROR números repetidos\n");
		return (1);
	}
	while (aux < argc - 1)
	{
		printf("%d\n", stack_a.stk[aux]);
		aux++;
	}
	free(stack_a.stk);
	return (0);
}
