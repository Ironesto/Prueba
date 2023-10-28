#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
void	push(int *p1, int *p2)
{
	int	aux;
	int	i;
	int	k;

	if (p2[0] == 0 && p2[1] == 0)
		return ;
	aux = 0;
	i = p1[aux];
	while(p1[aux])
	{
		k = p1[aux + 1];
		p1[aux + 1] = i;
		i = k;
		aux++;
	}
	p1[0] = p2[0];
	aux = 0;
	while (p2[aux])
		aux++;
	while(p2[aux - 3])
	{
		k = p2[aux - 1];
		p2[aux - 1] = i;
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
	while (p[aux])
		aux++;
	while(p[aux - 3])
	{
		k = p[aux - 1];
		p[aux - 1] = i;
		i = k;
		aux--;
	}
}
/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo. */

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	stack_b[10] = {16, 23, 55, 79, 101, 43, 88, 454};
	int	i;
	int	aux = 0;

	stack_a = malloc(sizeof(int) * (argc + 1));
	//stack_b = malloc(sizeof(int) * argc);
	while (i < argc - 1)
	{
		stack_a[i] = atoi(argv[i + 1]);
		i++;
	}
	push(stack_a, stack_b);
	while (aux < argc)
	{
		printf("%d\n", stack_b[aux]);
		aux++;
	}
	free(stack_a);
	//free(stack_b);
	return(0);
}