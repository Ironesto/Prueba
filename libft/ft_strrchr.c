#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *str, char ch)
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return(NULL);
    while (str[i])
        i++;
    i--;
    while (i != 0 && str[i] != ch)
        i--;
    if (i == 0)
        return(NULL);
    return (&str[i]);
}

/*int main()
{
    char str[] = "";
    char ch = 'h';
    printf("a:%s:a\n", strrchr(str, ch));
    printf("%s", ft_strrchr(str, ch));
    return (0);
}*/