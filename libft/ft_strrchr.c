/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:43:48 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/11 17:45:12 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char ch)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i])
		i++;
	i--;
	while (i != 0 && str[i] != ch)
		i--;
	if (i == 0)
		return (NULL);
	return ((char *)&str[i]);
}
