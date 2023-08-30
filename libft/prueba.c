#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"




void	*ft_memchr2(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

int main ()
{
    char s1[] = "fdred";
    int c = 'd';
    int n = 4;
    printf("%p\n", ft_memchr2(s1, c, n)); // si le pongo %s da violación
    printf("%p", memchr(s1, c, n));
    return (0);
}