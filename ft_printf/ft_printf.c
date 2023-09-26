#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
//#include "libft.h"

int	putnbr_len (long i)
{
	int	t;

	t = 0;
	if (i < 0)
	{
		t++;
		i = -i;
	}
	while (i > 0)
	{
		t++;
		i /= 10;
	}
	return (t);
}

int    ft_putnbr(int i)
{
    long n;
    char c;

    n = i;
    if (n < 0)
    {
        write (1, "-",1);
        n = -n;
    }
    if (n < 10)
    {
        c = n + 48;
        write (1, &c,1);
    }
    else
    {
        ft_putnbr(n / 10);
        c = (n % 10) + 48;
        write (1, &c,1);
    }
	return (putnbr_len(i));
}

int	ft_printf(char const *str, ...)
{
	int	i;
	int	t;
	va_list args;
    va_start (args, str);
	
	i = 0;
	t = 0;
	while (str[i])
	{
/*		if (str[i] == '%' && str[i + 1] == 'c')
			ft_putchar (va_arg (args, char));
		if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr (va_arg (args, char *));
		if (str[i] == '%' && str[i + 1] == 'p')
*/
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			t += ft_putnbr (va_arg(args, int)) - 2;
			i += 2;
		}
/*		if (str[i] == '%' && str[i + 1] == 'i')

		if (str[i] == '%' && str[i + 1] == 'u')

		if (str[i] == '%' && str[i + 1] == 'x')
			ft_putnbr_hexmi(va_arg(args, unsigned long));
		if (str[i] == '%' && str[i + 1] == 'X')
			ft_putnbr_hexma(va_arg(args, unsigned long));
		if (str[i] == '%' && str[i + 1] == '%')
*/
		write(1, &str[i], 1);
		i++;
	}
	printf("%d", i + t);
	return (t + i);
}

int main (void)
{
	ft_printf("hola %d que", -512);
    //printf("int: %d, float: %f char: %c str: %s\n", 15, 1.5, 'G', "string");
    return (0);
}


/*void	example (char *placeholders, ...)
{
    va_list args;
    va_start (args, placeholders);
	int	num_args = strlen(placeholders);

    int max = 0;
    int i = 0;
    while (i < num_args)
    {
        int x = va_arg (args, int);
        if (i == 0) max = x;
        else if (x == max) max = x;
    }
    return (max);
}*/
