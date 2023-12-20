/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:16 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/12/20 19:18:42 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez.
*/
void	swap(t_stk *stack)
{
	int	aux;

	aux = stack->num[0].nbr;
	stack->num[0].nbr = stack->num[1].nbr;
	stack->num[1].nbr = aux;
}
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr ra y rb al mismo tiempo.
*/

void	rotate(t_stk *stack)
{
	int	aux;
	int	i;
	int	k;

	aux = 0;
	i = stack->num[0].nbr;
	while (aux < stack->targ)
	{
		stack->num[aux].nbr = stack->num[aux + 1].nbr;
		aux++;
	}
	stack->num[aux - 1].nbr = i;
}

/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/

void	rotinv(t_stk *stack)
{
	int	aux;
	int	i;
	int	k;

	aux = 0;
	if (stack->num[0].nbr == 0 && stack->num[1].nbr == 0)
		return ;
	i = stack->num[stack->targ - 1].nbr;
	aux = stack->targ - 1;
	while (aux > 0)
	{
		stack->num[aux].nbr = stack->num[aux - 1].nbr;
		aux--;
	}
	stack->num[0].nbr = i;
}

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

void	push(t_stk *ent, t_stk *out)
{
	int	aux;
	int	k;

	if (out->num[0].nbr == 0 && out->num[1].nbr == 0)
		return ;
	aux = 0;
	rotinv(ent);
	ent->num[ent->targ].nbr = ent->num[0].nbr;
	ent->num[0].nbr = out->num[0].nbr;
	out->num[0].nbr = 0;
	rotate(out);
	out->targ -= 1;
	ent->targ += 1;
	//ft_see(*ent, *out);
}
