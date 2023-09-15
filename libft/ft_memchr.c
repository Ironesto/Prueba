/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:38:30 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/15 04:31:20 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (i < n && res[i])
	{
		if (res[i] == c)
			return ((void *)&res[i]);
		i++;
	}
	return (NULL);
}
