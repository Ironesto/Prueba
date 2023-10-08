/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:23 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/08 04:59:47 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50 // borrar esto antes de subir
# endif
# include <fcntl.h>
# include <stdio.h> // borrar
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*first_part(char *str);
char	*last_part(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, char ch);

#endif