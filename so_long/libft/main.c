#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("ERROR\n");
		return(1);
	}
	ft_printf("%d",checker(argv[1]));
	return(0);
}