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