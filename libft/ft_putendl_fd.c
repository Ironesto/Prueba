#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    write (fd, "\n", 1);
}

int main (void)
{
    int fd;
    char str[] = "hola msadsg \n que tal.";
    fd = open("/home/ironesto/Escritorio/Cursus/libft/file.txt", O_WRONLY);
    ft_putendl_fd(str, fd);
}