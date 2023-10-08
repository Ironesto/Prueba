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

char	*first_part(char *str)
{
	int	i;
	char *buffer;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i + 1] == '\n')
		i++;
	buffer = ft_substr(str, 0, i + 1);
	return (buffer);
}

char	*last_part(char *buffer)
{
	int	i;
	char	*str;

	if (buffer == NULL)
		return (NULL);
	str = ft_strdup(buffer);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	str = ft_strdup(&str[i]);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*last;
	char		*res;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i = read(fd, buffer, BUFFER_SIZE);
	}
	res = ft_strdup(first_part(buffer));
	last = last_part(buffer);
	while (i > 0)
	{
		if (ft_strchr(res, '\n'))
			return (res);
		i = read(fd, buffer, BUFFER_SIZE);
		res = ft_strjoin(res, first_part(last));
		last = last_part(buffer);
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
	printf("\n:FINAL:%s", get_next_line(fd));
	//printf("%s", last_part("hola \n mundoi"));
	return (0);
}