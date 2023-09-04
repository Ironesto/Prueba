#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char c;
    if (n < 0)
    {
        n = -n;
        write (fd, "-", 1);
    }

    if (n > 10)
        ft_putnbr_fd(n / 10, fd);
    c = (n % 10) + '0';
    write (fd,&c,1);
}

/*int main (void)
{
    int fd;
    char str[] = "hola mundo \n que tal.";
    fd = open("/home/ironesto/Escritorio/Cursus/libft/file.txt", O_WRONLY);
    ft_putnbr_fd(-123, fd);
}*/