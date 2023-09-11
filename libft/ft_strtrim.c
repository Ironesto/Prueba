/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:10 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 18:06:14 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] == set[i])
		i++;
	i = 0;
	return (s1);
}

int main (void)
{
	printf("%s", ft_strtrim("hola mundoho", "ho"));
	return (0);
}