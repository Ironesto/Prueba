RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRC = valid.c moves.c tools.c main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	

clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJ) 

fclean:
	make -C $(LIBFT) fclean
	$(RM) $(OBJ) $(NAME)

re: fclean all