/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:04 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 20:01:27 by gpaez-ga         ###   ########.fr       */
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
	while (i < n)
	{
		temp[i] = ((const char *)src)[i];
		i++;
	}
	dest = temp;
	return (dest);
}

/*int main()
{
	char dest[50] = "aaa";
	const char src[] = "lorem ipsum dolor sit amet";
	//printf("%s",ft_memmove(dest, src, 10));
	printf("%s",memmove((void*)dest, (const void*)src, 10));
	return (0);
}

	printf("src: %s\ndest : %s\ntemp : %s",src, dest, temp);*/