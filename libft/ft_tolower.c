#include <stdio.h>

char ft_tolower(char src)
{
    if (src >= 'A' && src <= 'Z')
        src += 32;
    return (src);
}