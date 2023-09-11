/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:04:12 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 17:08:55 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(const char *str, int i)
{
	int	num;

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

int	ft_atoi(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] <= 32)
		i++;
	if (nptr[i] == '+' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr(nptr, i + 1));
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr(nptr, i + 1) * -1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_putnbr(nptr, i));
	return (0);
}
