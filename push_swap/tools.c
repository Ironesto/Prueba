/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:40:47 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/11/24 19:54:56 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putnbr_atoi(const char *str, int i)
{
	long	num;

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

long	ft_atoli(const char *nptr)
{
	long	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1));
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1) * -1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_putnbr_atoi(nptr, i));
	return (0);
}

int	ft_isalldigit(char *wrd)
{
	int	i;

	i = 0;
	while (wrd[i])
	{
		if (!ft_strchr("+-0123456789", wrd[i]))
			return (1);
		i++;
	}
	return (0);
}
int	simp(s_stk stack)	//simplifica los numeros dados a 1, 2, 3...
{
	int	i;
	int	k;
	int	indx;
//comprobar str a cada numeor, guardar el valor en la estructura sin modificar str para que no de fallos la volver
// a pasar por la str
	indx = 1;
	i = 0;
	k = stack.stk[0];
	while (i < stack.targ)
	{
		if (stack.stk[i] < k)
			k = stack.stk[i];
	}
}
