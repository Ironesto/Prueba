/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:16 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/23 19:54:15 by gpaez-ga         ###   ########.fr       */
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
void	swap(int *p)
{
	int	aux;

	if (!p[1] || !p[0])
		return ;
	aux = p[0];
	p[0] = p[1];
	p[1] = aux;
}
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr ra y rb al mismo tiempo.
*/

void	rotate(s_stk *stack)
{
	int	aux;
	int	i;
	int	k;

	aux = 0;
	i = stack->stk[0];
	while (aux < stack->targ)
	{
		stack->stk[aux] = stack->stk[aux + 1];
		aux++;
	}
	stack->stk[aux - 1] = i;
}
/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/

void	rotinv(s_stk *stack)
{
	int	aux;
	int	i;
	int	k;

	aux = 0;
	i = stack->stk[stack->targ];
	aux = stack->targ - 1;
	while (aux > 0)
	{
		stack->stk[aux] = stack->stk[aux - 1];
		aux--;
	}
	stack->stk[0] = i;
}

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

void	push(s_stk *ent, s_stk *out)
{
	int	aux;
	int	i;
	int	k;

	if (out->stk[0] == 0 && out->stk[1] == 0)
		return ;
	aux = 0;
	rotinv(ent);
	i = ent->stk[0];
	while (ent->stk[aux])
		aux++;
	ent->stk[aux] = i;
	ent->stk[0] = out->stk[0];
	out->stk[0] = 0;
	rotate(out);
	out->targ -= 1;
	ent->targ += 1;
}
