NAME	=	libftprintf.h
LIBFT	=	./libft
SRC		= 	ft_printf.c	\

FLAGS	= -Wall -Werror -Wextra

OBJECTS = $(SRC%.c=%.o) 

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -ru $(name) $^

%.o:%.c
	$(cc) $(FLAGS) -o $@ -c $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:
	fclean all

.PHONY: make clean fclean re 