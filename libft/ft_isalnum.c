int ft_isalnum (char let)
{
    if (let >= 'a' && let <= 'z')
        return (1);
    if (let >= 'A' && let <= 'Z')
        return (1);
    if (let >= '0' && let <= '9')
        return (1);
    return(0);
}
