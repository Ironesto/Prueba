/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:04 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:05 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	temp[50];
	size_t	i;

	i = 0;
	while ((const char *)src && i < n)
	{
		temp[i] = ((const char *)src)[i];
		i++;
	}
	i = 0;
	while (temp[i])
	{
		((char *)dest)[i] = temp[i];
		i++;
	}
	return (dest);
}
