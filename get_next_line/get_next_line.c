/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/12 19:57:47 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* void	ft_leaks(void)
{
	system("leaks -q 'a.out'");
} */

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
	if (!str)
		return (NULL);
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		buffer = ft_join(buffer, str);
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
	static char	*buffer;
	char		*res;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(buffer, fd);
	if (buffer[0] == '\0')
		return (NULL);
	res = ft_line(buffer);
	buffer = ft_last(buffer);
	return (res);
}

/* int	main(void)
{
	atexit(ft_leaks);
	int			fd;
	char		*str;

	fd = open("./prueba.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("\nFINAL :%s||", get_next_line(fd));
	return (0);
} */
