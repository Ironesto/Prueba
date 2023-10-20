/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:48 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/25 19:07:33 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char ch)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{	
		if (str[i] == ch)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
