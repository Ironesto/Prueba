#include <stdio.h>

char ft_toupper(int src)
{
    if (src >= 'a' && src <= 'z')
        src -= 32;
    return (src);
}

/*int main()
{
    printf("%c", ft_toupper('3'));
    return (0);
}*/