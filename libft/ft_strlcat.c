#include <stdio.h>

int ft_strlcat(char *dest, const char *src, size_t n)
{
    int i;
    size_t j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;
    while (src[j] && j < n)
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (i);
}