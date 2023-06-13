##
## EPITECH PROJECT, 2023
## mylib
## File description:
## Make config file
##

SRC =	src/my_strlen.c			\
		src/analyse_event.c		\
		src/create_window.c		\
		src/create_text.c		\
		src/create_sprite.c		\
		src/get_buffer.c		\
		src/int_to_string.c		\
		src/my_strcat.c			\
		src/my_str_to_word_array.c\
		src/my_strcmp.c			\
		src/my_strdup.c \
		src/my_getnbr.c \
		src/str_array_to_int.c

OBJ =	$(SRC:.c=.o)

CPPFLAGS	=	-I./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp -r include/* ../include
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
