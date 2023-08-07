#include <stdio.h>
#include <string.h>

void *ft_memchr(void *s, int c, size_t n)
{
    int i;
    char *res;

    i = 0;
    res = NULL;
    while (((char *)s)[i] != c && i < n && ((char *)s)[i])
        i++;
    if (((char *)s)[i] == c)
    {
        res = &s[i];
        return (res);
    }
    return(NULL);
}

int main ()
{
    char s1[] = "fre";
    int c = 'd';
    int n = 4;
    printf("%d\n", ft_memchr(s1, c, n)); // si le pongo %s da violación
    printf("%s", memchr(s1, c, n));
    return (0);
}