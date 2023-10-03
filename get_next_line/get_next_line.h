/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:23 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/03 20:24:05 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5 // borrar esto antes de subir
# endif
# include <fcntl.h>
# include <stdio.h> // borrar
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*first_part(char *str, int len);
char	*last_part(char *str, int len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

#endif