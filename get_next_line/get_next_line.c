/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:21 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/12 03:14:38 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *buffer, int fd)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		str[i] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	str = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (str);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i - 1] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] && buffer[i - 1] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_last(char *buffer)
{
	char	*last;

	if (ft_strchr(buffer, '\n') != NULL)
		last = ft_strdup(ft_strchr(buffer, '\n') + 1);
	else
		last = ft_strdup(ft_strchr(buffer, '\0'));
	free(buffer);
	buffer = NULL;
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(buffer, fd);
	if (buffer[0] == '\0')
		return (NULL);	//meter un free?
	res = ft_line(buffer);
	buffer = ft_last(buffer);
	return (res);
}

int	main(void)
{
	int			fd;

	fd = open("./prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("\nFINAL :%s||", get_next_line(fd));
	return (0);
}
