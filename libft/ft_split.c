/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:40:29 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:49 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			j++;
		i++;
	}
	return (j);
}

char	*ft_save(char const *s, char c, size_t i)
{
	char	*res;
	int		j;

	j = i;
	while (s[j] != c && s[j])
		j++;
	res = malloc(sizeof(char) * (j - i) + 1);
	j = 0;
	while (s[i] && s[i] != c)
		res[j++] = s[i++];
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * ft_count(s, c) + 1);
	while (s[j])
	{
		if (s[j] && s[j] != c)
		{
			str[i] = ft_save(s, c, j);
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
		j++;
	}
	str[i] = 0;
	return (str);
}
