/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/02 19:47:03 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *first_part(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *last_part(char *str, int len)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	j = i;
	while (str[i])
		i++;
	res = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (str[j])
	{
		res[i] = str[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	j = read(fd, buffer, BUFFER_SIZE);
	while (j > 0)
	{	
		while (buffer[0] != '\0')
		{
			res = first_part(buffer, BUFFER_SIZE);
			buffer = last_part(buffer, BUFFER_SIZE);
		}
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		j = read(fd, buffer, BUFFER_SIZE);
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