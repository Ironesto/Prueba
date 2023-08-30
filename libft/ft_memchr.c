#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    char *res;

    i = 0;
    res = (char *)s;
    while (i < n && res[i])
    {    i++;
        if (res[i] == c)
            return ((void *)&res[i]);
    }
    return(NULL);
}

/*int main ()
{
    char s1[] = "frsed";
    int c = 's';
    int n = 4;
    printf("%p\n", ft_memchr(s1, c, n)); // si le pongo %s da violación
    printf("%p", memchr(s1, c, n));
    return (0);
}*/