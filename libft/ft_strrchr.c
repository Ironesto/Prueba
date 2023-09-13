/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:48 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/13 20:03:34 by gpaez-ga         ###   ########.fr       */
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

/*int main()
{
	char    str3[] = "";
    printf("%s",ft_strrchr(str3, '\0'));
	return (0);
}*/