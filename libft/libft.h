#ifndef		LIBFT_H
# define	LIBFT_H

#include <stdio.h>

int ft_isalpha(char let);
int	ft_isdigit(char let);
int ft_isalnum(char let);
int ft_isascii(char let);
int ft_isprint(char let);
int ft_strlen(char *str);
void ft_memset(void *str, int x, size_t n);
void ft_bzero(void *str, size_t n);


# endif