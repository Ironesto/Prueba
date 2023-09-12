/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:10 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/12 16:40:20 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] == set[i])
		i++;
	i = 0;
	while (s1[j] && set[i])
	{
			j--;
			i++;
	}
	res = ft_substr(s1, i, j - i + 1);
	return (res);
}
