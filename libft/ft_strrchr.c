/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:48 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/12 19:45:35 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char ch)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != ch)
		i--;
	if (str[i] == ch)
		return ((char *)&str[i]);
	else
		return (NULL);
}
