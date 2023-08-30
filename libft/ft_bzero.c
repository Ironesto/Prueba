#include <stdio.h>
//#include <strings.h>

void ft_bzero(void *str, size_t n)
{
    char *dest;
    size_t i;

    dest = (char *)str;
    i = 0;
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
}

/*int main()
{
    char str[] = "hola mundo que tal";
    ft_bzero(str, 4);
    printf("%c", str[5]);
    return (0);
}*/