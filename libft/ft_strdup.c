#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_strlen.c"

char *ft_strdup(const char *s)
{
    char    *res;
    size_t  i; 

    i = 0;
    res = malloc(sizeof(char) * ft_strlen(s) + 1);
    while (s[i])
        res[i++] = s[i];
    res[i] = '\0';
    return (res);
}

/*int main (void)
{
    printf("%s", ft_strdup("hola mundo"));
    return (0);
}*/