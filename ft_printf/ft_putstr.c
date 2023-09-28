#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
    return (ft_strlen(str));
}

int	ft_putpointer(unsigned long i, char *base)
{
	unsigned long	n;
	int		res;

	n = i;
	res = 0;
	if (n >= 16)
		res += ft_putpointer(n / 16, base);
	if (res == 0)
	{
		write(1, "0x",2);
		res += 2;
	}
	write(1, &base[n % 16], 1);
	res++;
	return (res);
}