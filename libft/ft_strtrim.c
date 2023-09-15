/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:10 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/15 04:59:26 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] == set[i])
		i++;
	res = ft_substr(s1, i, j);
	i = 0;
	while (s1[j - 1] && set[i] && s1[j - 1] == set[i])
	{
		j--;
		i++;
	}
	res = ft_substr(res, 0, ft_strlen(res) - i);
	return (res);
}

/*int main ()
{
	char s1[] = "lorem ipsum dolor sit amet";
	printf("%s", ft_strtrim(s1, "te"));
	return (0);
}*/