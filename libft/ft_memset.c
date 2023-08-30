#include <aio.h>

//#include <stdio.h>
//#include <string.h>

void ft_memset(void *str, int x, size_t n)
{
    size_t i;

    i = 0;

    while (((char *)str)[i] && i < n)
    {
        ((char *)str)[i] = (char)x;
        i++;
    }
}

/*int main ()
{
    char str[] = "hola mundo que tal";
    ft_memset(str, 't', 4);
    printf("%s", str);
    return (0);
}*/