#include <stdio.h>
#include <string.h>

int ft_strlcpy(char *dest, const char *src, size_t n)
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
    return (j);
}

/*int main()
{
    char dest[100] = "hola";
    char src[] = "mundo";
    printf("%d  ",strlcpy(dest, src, 3));
    printf("%d",ft_strlcpy(dest, src, 3));
    return (0);
}*/