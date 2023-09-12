#include "libft.h"
#include <stdlib.h>

void ft_strmapi(char *s, char (*f)(unsigned int, char*))
{
	int		i;
	char	*res;
	int		j;

	j = ft_strlen(s);
	res = malloc(sizeof(char) * (j + 1));
	i = 0;
    if (!s)
        return(NULL);
	while (i < j)
	{
		res = f(i,s[i]);
		i++;
	}
    res[i] = '\0';
    return (res);
}