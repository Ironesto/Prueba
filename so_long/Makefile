# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 18:09:58 by gpaez-ga          #+#    #+#              #
#    Updated: 2023/11/07 20:04:32 by gpaez-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = so_long
SRC = so_long.c main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft
LIBMLX = MLX42

INCLUDE = -I $(LIBMLX)/include -I $(LIBFT)
LFLAGS =  -L $(LIBFT) -L $(LIBMLX) -lmlx42
LIBS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

all: libmlx libft $(NAME)

ft_libft:
	@$(MAKE) -C $(LIBFT)
	
libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	$(CC) -o $@ -c $< $(INCLUDE) $(CCFLAGS)
#pendiente de explicación

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LFLAGS) $(LIBS) $(INCLUDE) -o $(NAME)


clean:
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean
	$(RM) $(OBJS) 

fclean:
	make -C $(LIBFT) fclean
	make -C $(LIBMLX) fclean
	$(RM) $(OBJS) $(NAME)

re: fclean all