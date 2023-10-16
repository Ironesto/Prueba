#include "libft/libft.h"

int	comp_rect(fd)
{
	int len;
	char *line;

	line = get_next_line(fd);
	len = ft_strlen(line);

	return(0);
}

int	main()
{
	int	fd;

	fd = open ("./map1.ber", O_RDONLY);
	comp_rect(fd);
	return(0);
}