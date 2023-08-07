#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, size_t n)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && i < n)
        i++;
    return (s1[i] - s2[i]);
}

/*int main()
{
    char s1[] = "";
    char s2[] = "sd";
    int n = 3;
    printf("%d \n", ft_strncmp(s1, s2, n));
    printf("%d", ft_strncmp(s1, s2, n));
    return (0);
}*/