##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

CC	=	gcc
SRC = 	malloc.c 		\
		realloc.c 		\
		calloc.c 		\
		reallocarray.c 	\
		free.c			\
		utils.c 		\

OBJ =	${SRC:.c=.o}
NAME =	libmy_malloc.so

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c -Wall -Wextra -Werror -fpic -fno-builtin $(SRC)
	gcc -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all