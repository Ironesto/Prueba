#include <stdlib.h>
#include <stdio.h>

static long	ft_putnbr_atoi(const char *str, int i)
{
	long	num;

	num = 0;
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		num += (str[i] - '0');
		num *= 10;
		i++;
	}
	num += (str[i] - '0');
	return (num);
}

long	ft_atoli(const char *nptr)
{
	long	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1));
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		return (ft_putnbr_atoi(nptr, i + 1) * -1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (ft_putnbr_atoi(nptr, i));
	return (0);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_save(char const *s, char c, size_t i)
{
	char	*res;
	size_t	j;

	j = i;
	while (s[j] != c && s[j])
		j++;
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str || s == NULL)
		return (NULL);
	while (s[j])
	{
		if (s[j] && s[j] != c)
		{
			str[i] = ft_save(s, c, j);
			if (str[i] == NULL)
				return (ft_free(str));
			i++;
			while (s[j + 1] && s[j + 1] != c)
				j++;
		}
		j++;
	}
	str[i] = NULL;
	return (str);
}

int main(int argc, char **argv)
{
	int	*stack_a;
	char **spt;
	int	i;
	int	k;
	int t = 0;
	int aux = 0;
	int l = 0;
	i = 0;
	while (i < argc - 1)
	{
		k = 0;
		spt = ft_split(argv[i + 1], ' ');
		while (spt[k])
		{
			if ((spt[k][0] < '0' || spt[k][0] > '9') && spt[k][0] != '-' && spt[k][0] != '+')
				return (1);
			k++;
			t++;	
		}
		i++;
	}
	printf("total %d\n", t);
	stack_a = malloc(sizeof(int) * t);
	spt = NULL;
	i = 0;
	k = 0;
	
	while (i < argc - 1)
	{
		l = 0;
		spt = ft_split(argv[i + 1], ' ');
		while (spt[l])
		{
			stack_a[k] = ft_atoli(spt[l]);
			if (ft_atoli(spt[l]) > 2147483647 || ft_atoli(spt[l]) < -2147483648)
				return (1);
			k++;
			l++;
		}
		i++;
	}
	i = 0;
	while (stack_a[i])
	{
		k = i + 1;
		while(stack_a[k])
		{
			if (stack_a[i] == stack_a[k])
				return(1);
			k++;
		}
		i++;
	}
	while (stack_a[aux])
	{
		printf("%d\n", stack_a[aux]);
		aux++;
	}

	return (0);
}