#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *str, char ch)
{
    int i;

    i = 0;
    while (str[i] && str[i] != ch)
        i++;
    return((char *)&str[i]);
}

/*int main()
{
    char str[] = "hpola mundo que tal hpola do";
    char ch = 'l';
    printf("%s\n",strchr(str, ch));
    printf("%s",ft_strchr(str, ch));
    return (0);
}*/