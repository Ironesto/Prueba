/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:27 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/29 03:35:44 by ironesto         ###   ########.fr       */
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
	else
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
		if (str[i] == '%' && ft_percent(str, args, i) != 0)
		{
			t += ft_percent(str, args, i + 1);
			if (str[i + 2] == '\0')
				return (t + i);
			else
				i += 2;
		}
		else if (str[i] == '%' && str[i + 1] != '\0' && ft_percent(str, args, i) == 0)
			i++;
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
	int		num3;

	num1 = 2147483648;
	num2 = -2147483648;
	num3 = num1;
	ft_printf("c: -%c", '\0');
	printf("\n");
	printf("c: -%c", '\0');
	printf("\n");
	ft_printf("s: -%s-", str);
	printf("\n");
	printf("s: -%s", str);
	printf("\n");
	ft_printf("p: %p", str);
	printf("\n");
	printf("p: %p", str);
	printf("\n");
	ft_printf("d & i: %d & %i", num3, num3);
	printf("\n");
	printf("d & i: %d & %i", num3, num3);
	printf("\n");
	ft_printf("u: %u", num3);
	printf("\n");
	printf("u: %u", num3);
	printf("\n");
	ft_printf("x & X: %x %X", num3, num3);
	printf("\n");
	printf("x & X: %x %X", num3, num3);
	printf("\n");
	ft_printf("percent: %%");
	printf("\n");
	printf("normpercent: %%");
	printf("\n");
	ft_printf("novar: %");
	printf("\n");
	printf("novar: %");
	printf("\n");
	return (0);
}
