#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return (dest);
}

int main()
{
    char src[] = "hola mundo";
    char dest[50];
    ft_memcpy(dest, src, 5);
    printf("%s", dest);
    return(0);
}