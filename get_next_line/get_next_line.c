/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/05 20:10:25 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*last;
	char		*res;
	int			j;
	int			i;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = read(fd, buffer, BUFFER_SIZE);
	res = first_part(buffer);
	while (i > 0)
	{
		while (buffer[j] && buffer[j] != '\n')
			j++;
		if (buffer[j] == '\n')
			{
				if (last != NULL)
					res  = ft_strjoin(last, res);
				res  = ft_strjoin(res, first_part(buffer));
				return (res);
			}
		
		i = read(fd, buffer, BUFFER_SIZE);
		res  = ft_strjoin(res, buffer);
		j = 0;
	}
	return (res);
}

int main()
{
	int	fd;

	fd = open("./prueba.txt", O_RDONLY);
	printf("@%s@\n", get_next_line(fd));
	printf("$%s$\n", get_next_line(fd));
	printf("$%s$\n", get_next_line(fd));
	printf("$%s$\n", get_next_line(fd));
	//printf("$%s$\n", get_next_line(fd)); 
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
	static char	*last;
	char		*res;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buffer, BUFFER_SIZE);
	res = ft_strdup(buffer);
	while (buffer[0] != '\0')
	{
		while (buffer[j] && buffer[j] != '\n')
			j++;
		if (buffer[j] == '\n')
			{
				buffer = last_part(buffer);
				printf("!%s!\n", buffer);
				return (res);
			}
		else
		{
			read(fd, buffer, BUFFER_SIZE);
			//printf("!%s!\n", buffer);
			res  = ft_strjoin(res, first_part(buffer);
		}
		j = 0;
	}
	return (res);
}*/