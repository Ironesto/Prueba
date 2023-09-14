/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:49:36 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 04:27:35 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] == little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i - j]);
		}
		i++;
	}
	return (NULL);
}

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len && big[i] != little[j])
		i++;
	while (big[i] == little[j])
	{
		i++;
		j++;
	}
	if (little[j + 1])
		return ((char *)&big[i - j]);
	return (NULL);
}


int main()
{
	printf("%s", newft_strnstr("lorem ipsum dolor sit amet", "ipsum", 5));
	return (0);
}*/