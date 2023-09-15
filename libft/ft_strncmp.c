/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:29 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/15 04:32:02 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
	{
		if (ft_isascii(s1[i + 1]) == 0)
			return (s2[i + 1] - s1[i + 1]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int main()
{
	printf("%d", ft_strncmp("abcdefgh","abcdwxyz", 0));
	printf(" y %d\n", strncmp("abcdefgh","abcdwxyz", 0));
	return(0);
}*/