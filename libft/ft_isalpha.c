int ft_isalpha (char let)
{
    if (let >= 'a' && let <= 'z')
        return (1);
    if (let >= 'A' && let <= 'Z')
        return (1);
    return(0);
}
