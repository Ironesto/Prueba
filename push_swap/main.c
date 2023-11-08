#include "push_swap.h"



int	main(int argc, char **argv)
{
	int	*stack_a;
	int	stack_b[10] = {16, 23, 55, 79, 101, 43, 88};
	int	i;
	int	aux = 0;

	i = 0;
	stack_a = malloc(sizeof(int) * (argc));
	//stack_b = malloc(sizeof(int) * argc);
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	while (stack_a[aux])
	{
		printf("%d\n", stack_a[aux]);
		aux++;
	}
	free(stack_a);
	//free(stack_b);
	return(0);
}