/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:04 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/15 20:36:29 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else if (d < s)
		ft_memcpy(dest, src, n);
	return (dest);
}

/*int main()
{
	char dest[50] = "aaafdf";
	const char src[] = "lor";
	//printf("%s",ft_memmove(dest, src, 10));
	printf("%s",ft_memmove((void*)dest, (const void*)src, 10));
	return (0);
}*/