#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write (fd, &c, 1);
}

/*int main (int argc, char **argv)  
{
    int fd;
    fd = open("/home/ironesto/Escritorio/Cursus/libft/file.txt", O_WRONLY);
    ft_putchar_fd('G',fd);
    return (0);
}*/