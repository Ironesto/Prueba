/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:27 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/27 19:04:09 by gpaez-ga         ###   ########.fr       */
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
			//ft_putchar(va_arg(args, char));
			t--;
			i += 2;
		}
		// if (str[i] == '%' && str[i + 1] == 's')
		// ft_putstr (va_arg (args, char *));
		// if (str[i] == '%' && str[i + 1] == 'p')
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			t += ft_putnbr(va_arg(args, int), "0123456789") - 2;
			i += 2;
		}
		//if (str[i] == '%' && str[i + 1] == 'i')
		//if (str[i] == '%' && str[i + 1] == 'u')
		if (str[i] == '%' && str[i + 1] == 'x')
		{
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef") - 2;
			i += 2;
		}
		if (str[i] == '%' && str[i + 1] == 'X')
		{
			t += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF") - 2;
			i += 2;
		}
		//if (str[i] == '%' && str[i + 1] == '%')
		write(1, &str[i], 1);
		i++;
	}
	printf("\n%d", i + t);
	va_end(args);
	return (t + i);
}

int	main(void)
{
	unsigned int  j = 522;
	ft_printf("el numero %x es unsigned", -522);
	// printf("int: %d, float: %f char: %c str: %s\n", 15, 1.5, 'G', "string");
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
