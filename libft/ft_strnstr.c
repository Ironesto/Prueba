#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (little[0] == '\0')
        return ((char *)big);
    while (big[i] && i < len && big[i] != little[j])
        i++;
    while (big[i] == little[j])
    {
        i++;
        j++;
    }
    if (little[j + 1])
        return ((char *)&big[i - j]);
    return (NULL);
}

/*int main()
{
    char str[] = "hola mundo que tal";
    char find[] = "la";
    int len = 15;
    printf("%s\n", ft_strnstr(str, find, len));
    return (0);
}*/