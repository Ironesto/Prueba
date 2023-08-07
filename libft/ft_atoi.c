#include <stdio.h>
#include <stdlib.h>

int ft_putnbr(const char *str, int i)
{
    int num;

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

int ft_atoi(const char *nptr)
{
    int i;

    i = 0;
    while (nptr[i] <= 32)
        i++;
    if (nptr[i] == '+' && nptr[i] >='0' && nptr[i] <= '9')
        return(ft_putnbr(nptr, i + 1));
    if (nptr[i] == '-' && nptr[i] >='0' && nptr[i] <= '9')
        return(ft_putnbr(nptr, i + 1) * -1);
    if (nptr[i] >='0' && nptr[i] <= '9')
        return(ft_putnbr(nptr, i));
    return (0);
}

int main()
{
    char str[] = "\t \n   + 123a mundo 34";
    printf("%d", ft_atoi(str));
    printf("%d", atoi(str));
    return (0);
}