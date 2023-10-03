/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/03 20:24:00 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buffer, BUFFER_SIZE);
	res = ft_strdup(buffer);
	while (buffer[0] != '\0')
	{
		while (buffer[j] && buffer[j] != '\n' && j < BUFFER_SIZE)
			j++;
		if (buffer[j] == '\n')
			return (first_part(res, BUFFER_SIZE));
		else
		{
			read(fd, buffer, BUFFER_SIZE);
			res  = ft_strjoin(res, first_part(buffer, BUFFER_SIZE));
		}
		j = 0;
	}
	return (res);
}

int main()
{
	int	fd;

	fd = open("./prueba.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return(0);
}

/*char *get_next_line(int fd)
{
	static char *buffer;
	char *res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buffer, BUFFER_SIZE);
	res = first_part(buffer, BUFFER_SIZE);
	buffer = last_part(buffer, BUFFER_SIZE);
	return (res);
}*/

/*char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[0] != '\0')
	{
		while (buffer[j] && buffer[j] != '\n' && j < BUFFER_SIZE)
			j++;
		if (buffer[j] == '\n')
		res = first_part(buffer, BUFFER_SIZE);
		buffer = last_part(buffer, BUFFER_SIZE);
	}
	return (res);
}*/