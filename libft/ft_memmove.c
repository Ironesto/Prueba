/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:04 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/13 02:48:39 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	if ((const char *)dest > (const char *)src)
		temp = (char *)dest;
	else
		temp = (char *)src;
	while ((const char *)src && i < n)
	{
		temp[i] = ((const char *)src)[i];
		i++;
	}
	temp[i] = '\0';
	return (dest);
}
