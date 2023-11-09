#include "push_swap.h"

int main(int argc, char **argv)
{
	s_stk	stack_a;
	int	i;
	int	k;
	int aux = 0;
	int l = 0;
	i = 0;
	
	i = 0;
	k = 0;
	stack_a.stk = compnums(argc, argv, stack_a);
	if (stack_a.stk == 0)
	{
		printf("ERROR guardando los elementos\n");
		return(1);
	}
	if (comprep(stack_a) == 1)
	{
		ft_printf("ERROR números repetidos\n");
		return(1);
	}
	while (stack_a.stk[aux])
	{
		printf("%d\n", stack_a.stk[aux]);
		aux++;
	}
	free(stack_a.stk);
	//ft_free(stack_a.spt);
	return (0);
}
