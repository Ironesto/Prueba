/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:54:25 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/26 20:31:41 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(int i, char *base)
{
	long	n;
	int		res;

	n = i;
	res = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		res++;
	}
	if (n > 10)
		res += ft_putnbr(n / ft_strlen(base), base);
	write(1, &base[n % ft_strlen(base)], 1);
	res++;
	return (res);
}
