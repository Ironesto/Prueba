/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:10 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/15 20:11:27 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	if (j == 0)
		res = ft_strdup(s1);
	else
		res = ft_substr(s1, i, j - i + 1);
	return (res);
}

/*int main ()
{
	char s1[] = "      ";
	printf("%s\n", ft_strtrim(s1, ""));
	return (0);
}*/