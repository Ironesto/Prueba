#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    char *cs1;
    char *cs2;

    cs1 = (char *)s1;
    cs2 = (char *)s2;
    ft_strncmp(cs1, cs2, n);
    if (ft_strncmp(cs1, cs2, n) > 0)
        return (1);
    if (ft_strncmp(cs1, cs2, n) < 0)
        return (-1);
    return(0);
}

/*int main(void)
{
    printf("%d\n",ft_memcmp("az", "ac", 2));
    printf("%d\n",memcmp("az", "ac", 2));
    printf("%d",strncmp("ag", "ac", 2));
    return (0);
}*/