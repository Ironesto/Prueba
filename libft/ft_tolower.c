#include <stdio.h>

char ft_tolower(int src)
{
    if (src >= 'A' && src <= 'Z')
        src += 32;
    return (src);
}