/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/08 05:00:35 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_part(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	str = ft_substr(str, 0, i);
	return (str);
}

char	*last_part(char *buffer)
{
	int	i;
	char	*str;

	str = ft_strdup(buffer);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	return (&str[i]);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i = read(fd, buffer, BUFFER_SIZE);
	}
	res = ft_strdup(buffer);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		res = ft_strjoin(res, first_part(buffer));
		buffer = last_part(buffer);
		if (ft_strchr(res, '\n'))
			return (res);
	}
	return (res);
}

int	main()
{
	int	fd;

	fd = open("./prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\nFINAL :%s||", get_next_line(fd));
	//printf("%s", last_part("hola \n mundoi"));
	return (0);
}
/* char	*get_next_line(int fd)
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
} */

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