/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:28 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 03:55:58 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t n)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i] && i < n)
	{
		((char *)str)[i] = (unsigned char)x;
		i++;
	}
}
