void	ft_putnbr_hexma(int nbr, char *base)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		write (1, "-",1);
		n = -n;
	}
	if (n < 16)
		write(1, &base[n % 16], 1);
	else
	{
		ft_putnbr_hexma(n / 16, base);
		write(1, &base[n % 16], 1);
	}
}
