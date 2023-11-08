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

	if(!p[1] || !p[0])
		return ;
	aux = p[0];
	p[0] = p[1];
	p[1] = aux;
}

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/
void	push(int *ent, int *out)
{
	int	aux;
	int	i;
	int	k;

	if (out[0] == 0 && out[1] == 0)
		return ;
	aux = 0;
	i = ent[aux];
	while(ent[aux])
	{
		k = ent[aux + 1];
		ent[aux + 1] = i;
		i = k;
		aux++;
	}
	ent[0] = out[0];
	aux = 0;
	while (out[aux])
		aux++;
	while(out[aux - 1])
	{
		k = out[aux - 1];
		out[aux - 1] = i;
		i = k;
		aux--;
	}
}
/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr ra y rb al mismo tiempo.
*/
void	rotate(int *p)
{
	int aux;
	int	i;
	int	k;

	aux = 0;
	i = p[0];
	while(p[aux])
	{
		p[aux] = p[aux + 1];
		aux++;
	}
	p[aux - 1] = i;
}
/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/

void	rotinv(int *p)
{
	int aux;
	int	i;
	int	k;

	aux = 0;
	while(p[aux])
		aux++;
	i = p[aux - 1];
	aux--;
	while(p[aux])
	{
		p[aux] = p[aux - 1];
		aux--;
	}
	p[0] = i;
}
