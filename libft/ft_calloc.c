/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:41 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/16 19:14:29 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	while (res[i])
		res[i++] = 0;
	return ((void *)res);
}
