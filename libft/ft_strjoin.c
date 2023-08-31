#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_strlen.c"

char *ft_strjoin(const char *s1, const char *s2)
{
    int i;
    int j;
    char *s3;

    i = 0;
    j = 0;
    s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

int main(void)
{
    printf("%s", ft_strjoin("hola", " mundi"));
    return (0);
}