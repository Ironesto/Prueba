/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:38:40 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:34 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	ft_strncmp(cs1, cs2, n);
	if (ft_strncmp(cs1, cs2, n) > 0)
		return (1);
	if (ft_strncmp(cs1, cs2, n) < 0)
		return (-1);
	return (0);
}
