/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:29 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 20:31:49 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
	{
		if (ft_isascii(s1[i]) == 1 && ft_isascii(s1[i]) == 1)
		{
			if (s2[i] == '\0' || s1[i] == '\0')
				return (0);
			i++;
		}
		else
			return (1);
	}
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/*int main()
{
	printf("%d", ft_strncmp("teste\200","test", 6));
	printf("\n%d", strncmp("teste\200","test", 6));
	return(0);
}*/