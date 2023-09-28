/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:27 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/28 20:06:31 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char const *str, va_list args, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)) - 2);
	else if (str[i + 1] == 'p')
		return (ft_putpointer(va_arg(args, unsigned long), "0123456789abcdef")
			- 2);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789") - 2);
	else if (str[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), "0123456789") - 2);
	else if (str[i + 1] == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef")
			- 2);
	else if (str[i + 1] == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF")
			- 2);
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		return (-1);
	}
	return (0);
}

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
		if (str[i] == '%')
		{
			t += ft_percent(str, args, i);
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (t + i);
}

int	main(void)
{
	char	str[] = "hola";
	int		num1;
	int		num2;

	num1 = 522;
	num2 = -522;
	ft_printf("c: %c\n", 'S');
	printf("c: %c\n", 'S');
	//ft_printf("s: %s\n", str);
	printf("s: %s\n", str);
	ft_printf("p: %p\n", str);
	printf("p: %p\n", str);
	ft_printf("d & i: %d & %i\n", num2, num2);
	printf("d & i: %d & %i\n", num2, num2);
	ft_printf("u: %u\n", num2);
	printf("u: %u\n", num2);
	ft_printf("x & X: %x %X\n", num2, num2);
	printf("x & X: %x %X\n", num2, num2);
	ft_printf("percent: %w zzz");
	printf("\nnormpercent: %w zzz");
	return (0);
}
