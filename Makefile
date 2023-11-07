# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 18:09:58 by gpaez-ga          #+#    #+#              #
#    Updated: 2023/11/07 02:28:12 by ironesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

CC = gcc
CCFLAGS =

NAME = so_long
SRC = so_long.c main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft
LIBMLX = MLX42

INCLUDE = -I $(LIBMLX)/include -I $(LIBFT)
LFLAGS = -L $(LIBFT) -lft -L $(LIBMLX) -lmlx42
LIBS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) -o $@ -c $< $(INCLUDE) $(CCFLAGS)
#pendiente de explicación

$(NAME): $(OBJ) 
	$(CC) $(CCFLAGS) $(OBJ) $(LFLAGS) $(LIBS) $(INCLUDE) -o $(NAME)