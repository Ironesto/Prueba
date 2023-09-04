#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
        write (fd, &s[i++], 1);;
}

/*int main (void)
{
    int fd;
    char str[] = "hola mundo \n que tal.";
    fd = open("/home/ironesto/Escritorio/Cursus/libft/file.txt", O_WRONLY);
    ft_putstr_fd(str, fd);
}*/