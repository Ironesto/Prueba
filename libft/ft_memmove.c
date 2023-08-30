#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char temp[50];
    size_t i;

    i = 0;
    while ((const char *)src && i < n)
    {
        temp[i] = ((const char *)src)[i];
        i++;
    }
    //src = NULL;
    i = 0;
    while (temp[i])
    {
        ((char *)dest)[i] = temp[i];
        i++;
    }
    //((char *)dest)[i] = '\0';
    return (dest);
}
/*int main()
{
    char src[] = "hola mundo";
    char dest[50];
    memmove(dest, src, 20);
    printf("%s\n",dest);
    ft_memmove(dest, src, 20);
    printf("%s",dest);
    return(0);
}*/