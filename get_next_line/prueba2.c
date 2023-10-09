#include "prueba.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
		return ((char *)&str[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*res;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s[start] && len > 0)
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*last_part(char *buffer)
{
	int	i;
	char	*str;

	str = ft_strdup(buffer);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str = ft_strdup(&buffer[i]);
	//free(buffer);
	return (str);
}

char *ft_read(char *last, char *buffer, int fd)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 1;
	line = ft_strjoin(last, buffer);
	//printf("//%s//\n", line);
	while(!ft_strchr(buffer, '\n') && k > 0)
	{
		line = ft_strjoin(line, buffer);
		k = read(fd, buffer, BUFFER_SIZE);
	}
	j = ft_strlen(line);
	while (buffer[i] && buffer[i - 1] != '\n')
	{
		line[j] = buffer[i];
		j++;
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	static char	*last;
	int			i;

	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		{buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		last = ft_strdup("");
		}
	res = ft_read(last, buffer, fd);
	buffer = ft_strchr(buffer, '\n') + 1;
	//free (buffer);
	//buffer = ft_strdup(last);
	//printf("$$%s$$", last);
	return (res);
}

int	main()
{
	int	fd;

	fd = open("./prueba.txt", O_RDONLY);
	printf("!!%s!!", get_next_line(fd));
	printf("%s!!", get_next_line(fd));
	//printf("%s!!", get_next_line(fd));
	/*printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\n:FINAL:%s", get_next_line(fd)); */
	//printf("%s", last_part("hola \n mundoi"));
	return (0);
}