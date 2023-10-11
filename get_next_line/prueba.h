/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:22 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/11 19:09:23 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRUEBA_H
# define PRUEBA_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15 // borrar esto antes de subir
# endif
# include <fcntl.h>
# include <stdio.h> // borrar
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif