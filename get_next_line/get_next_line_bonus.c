/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:45:14 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/18 19:41:11 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join(char *buffer, char *str)
{
	char	*temp;

	temp = ft_strjoin(buffer, str);
	free (buffer);
	buffer = temp;
	return (buffer);
}

char	*ft_read(char *buffer, int fd)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free (buffer);
			return (NULL);
		}
		str[i] = '\0';
		buffer = ft_join(buffer, str);
		if (buffer[0] == 0)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
	}
	free(str);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	size_t	size;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	line = ft_substr(buffer, 0, size + 1);
	return (line);
}

char	*ft_last(char *buffer)
{
	char	*last;

	if (ft_strchr(buffer, '\n') != NULL)
		last = ft_strdup(ft_strchr(buffer, '\n') + 1);
	else
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	buffer = NULL;
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*res;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = ft_read(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	res = ft_line(buffer[fd]);
	buffer[fd] = ft_last(buffer[fd]);
	return (res);
}
