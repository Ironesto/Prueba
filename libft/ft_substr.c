/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:44:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 19:48:46 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if ((int)start >= ft_strlen(s))
		return (res = "\0");
	if (s[0] == '\0')
		return (res = "\0");
	while (s[start] && len > 0)
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = '\0';
	return (res);
}
