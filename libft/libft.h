#ifndef		LIBFT_H
# define	LIBFT_H
# include <stdio.h>

int ft_isalpha(char let);
int	ft_isdigit(char let);
int ft_isalnum(char let);
int ft_isascii(char let);
int ft_isprint(char let);
int ft_strlen(char *str);
void ft_memset(void *str, int x, size_t n);
void ft_bzero(void *str, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
char *strlcpy(char *dest, const char *src, size_t n);
int ft_strlcat(char *dest, const char *src, size_t n);
char ft_toupper(char src);
char ft_tolower(char src);
char *ft_strchr(char *str, char ch);
char *ft_strrchr(char *str, char ch);
int ft_strncmp(char *s1, char *s2, size_t n);
void *ft_memchr(void *s, int c, size_t n);
char *ft_strnstr(char *big, char *little, size_t len);
int ft_atoi(const char *nptr);
# endif