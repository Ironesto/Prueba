/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:27 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/28 04:09:20 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		t;
	va_list	args;

	va_start(args, str);
	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			t--;
		}
		if (str[i] == '%' && str[i + 1] == 's')
			t += ft_putstr(va_arg(args, char *)) - 2;
		if (str[i] == '%' && str[i + 1] == 'p')
			t += ft_putpointer(va_arg(args, unsigned long), "0123456789abcdef") - 2;
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			t += ft_putnbr(va_arg(args, int), "0123456789") - 2;
		if (str[i] == '%' && str[i + 1] == 'u')
			t+= ft_putnbr_u(va_arg(args, unsigned int), "0123456789") - 2;
		if (str[i] == '%' && str[i + 1] == 'x')
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef") - 2;
		if (str[i] == '%' && str[i + 1] == 'X')
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF") - 2;
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			t--;
		}
		if (str[i] == '%' && str[i + 1] != '\0')
			i += 2;
		write(1, &str[i], 1);
		i++;
	}
	printf("%d\n", i + t);
	va_end(args);
	return (t + i);
}

int	main(void)
{
	char str[] = "hola";
	int num1 = 522;
	int num2 = -522;
	ft_printf("c: %c\n", 'S');
	printf("c: %c\n", 'S');
	ft_printf("s: %s\n", str);
	printf("s: %s\n", str);
	ft_printf("p: %p\n", str);
	printf("p: %p\n", str);
	ft_printf("d & i: %d & %i\n", num2, num2);
	printf("d & i: %d & %i\n", num2, num2);
	ft_printf("u: %u\n", num2);
	printf("u: %u\n", num2);
	ft_printf("x & X: %x %X\n", num2, num2);
	printf("x & X: %x %X\n", num2, num2);
	ft_printf("percent: %%\n");
	printf("percent: %%\n");
	return (0);
}

/*void	example (char *str, va_list args, int i)
{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			return(-1);
		}
		if (str[i] == '%' && str[i + 1] == 's')
			return(ft_putstr(va_arg(args, char *)) - 2);
		if (str[i] == '%' && str[i + 1] == 'p')
			t += ft_putpointer(va_arg(args, void *), "0123456789abcdef") - 2;
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			t += ft_putnbr(va_arg(args, int), "0123456789") - 2;
		if (str[i] == '%' && str[i + 1] == 'u')
			t+= ft_putnbr_u(va_arg(args, unsigned int), "0123456789") - 2;
		if (str[i] == '%' && str[i + 1] == 'x')
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef") - 2;
		if (str[i] == '%' && str[i + 1] == 'X')
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF") - 2;
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			t--;
		}
}*/
