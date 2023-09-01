#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_ext(int num)
{
    int i;

    i = 0;
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}

char *ft_putnbr(char *str, int i, int num)
{
    str[i] = (num % 10) + '0';
    if (i > 0)
        ft_putnbr(str, i - 1, num / 10);
    return(str);
}

char *ft_itoa(int n)
{
    char *res;
    int j;

    j = ft_ext(n);
    res = malloc(sizeof(char) * j);
    ft_putnbr(res, j - 1, n);
    return (res);
}

int main (void)
{
    printf("%s",ft_itoa(12346));

    return(0);
}