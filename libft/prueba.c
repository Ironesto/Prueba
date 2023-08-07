#include <stdio.h>
#include <stdlib.h>

int ft_putnbr(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i + 1] >= '0' && str[i + 1] <= '9')
    {
        num += (str[i] - '0');
        num *= 10;
        i++;
    }
    num += (str[i] - '0');
    return (num);
}

int main()
{
    printf("%d", ft_putnbr("423"));
    return(0);
}