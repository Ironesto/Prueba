int ft_isprint(char let)
{
    if (let >= 32 && let <= 126)
        return (1);
    return (0);
}