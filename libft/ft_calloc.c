#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    int *res;
    int i;

    i = 0;
    if(nmemb == 0 || size == 0)
        return (NULL);
    if (nmemb * size > 2147483647)
        return(NULL);
    res = malloc(nmemb * size);
    while (res[i])
        res[i++] = 0;
    return ((void *)res);
}
