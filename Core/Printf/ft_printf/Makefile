NAME	=	libftprintf.a
SRC		= 	ft_printf.c			\
			ft_putnbr_fd.c		\
			ft_putstr_strlen.c	\
			ft_strlcpy.c		\
			ft_strlen.c			\
			printf_utils.c

TMPSRC	=	ft_printf.c			\
			ft_putnbr_fd.c		\
			ft_putstr_strlen.c	\
			ft_strlcpy.c		\
			ft_strlen.c			\
			printf_utils.c		\

FLAGS	=	-Wall -Werror -Wextra

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $^

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

exec:
	gcc $(FLAGS) $(TMPSRC) 

eclean:
	rm -f a.out

re: fclean all

.PHONY: make clean fclean re all