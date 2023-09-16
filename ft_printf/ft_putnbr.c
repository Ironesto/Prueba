void    ft_putnbr(int i)
{
    long n;
    char c;

    n = i;
    if (n < 0)
    {
        write (1, "-",1);
        n = -n;
    }
    if (n < 10)
    {
        c = n + 48;
        write (1, &c,1);
    }
    else
    {
        ft_putnbr(n / 10);
        c = (n % 10) + 48;
        write (1, &c,1);
    }
}
