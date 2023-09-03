#ifndef		LIBFT_H
# define	LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int ft_isalpha(char let);
int	ft_isdigit(char let);
int ft_isalnum(char let);
int ft_isascii(char let);
int ft_isprint(char let);
int ft_strlen(const char *str);
void ft_memset(void *str, int x, size_t n);
void ft_bzero(void *str, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
char *strlcpy(char *dest, const char *src, size_t n);
int ft_strlcat(char *dest, const char *src, size_t n);
char ft_toupper(int src);
char ft_tolower(int src);
char *ft_strchr(const char *str, char ch);
char *ft_strrchr(const char *str, char ch);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(void *s, int c, size_t n);
//int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
//char *ft_strtrim(char const *s1, char const *set);
//char **ft_split(char const *s, char c);
char *ft_itoa(int n);
# endif