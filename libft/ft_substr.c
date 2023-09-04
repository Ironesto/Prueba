#include <stdio.h>
#include<stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    char *res;
    res = malloc(sizeof(char) * len + 1);

    i = 0;
    while (s[start] && len > 0)
    {
        res[i++] = s[start++];
        len--;
    }
    res[i] = '\0';
    return (res);
}

/*int main(void)
{
    printf("%s",ft_substr("HOLA MUNDO",0, 3));
    return (0);
}*/