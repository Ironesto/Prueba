/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:42:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/13 02:28:49 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j < n - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (n > i - j)
		return (ft_strlen(src) + (i - j));
	else
		return (n + ft_strlen(src));
}

/*int main()
{
	char dest[] = "hola";
	char src[] = "mundo";
	ft_strlcat(dest, src, 2);
	char dest2[] = "hola";
	char src2[] = "mundo";
	//strlcat(dest2, src2, 8);
	return(0);
}*/