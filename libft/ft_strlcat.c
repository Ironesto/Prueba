/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:42:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 04:06:55 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && i < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (n > i - j)
		return (ft_strlen(src) + (i - j));
	else
		return (n + ft_strlen(src));
}

/*int main()
{
	char dest[] = "aaaa";
	char src[] = "lorem ipsum dolor sit amet";
	ft_strlcat(dest, src, 4);
	char dest2[] = "hola";
	char src2[] = "mundo";
	//strlcat(dest2, src2, 8);
	return(0);
}*/