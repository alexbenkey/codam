NAME = gnl.out
BNAME = gnl_b.out
SRC =	get_next_line_utils.c		\
	  	get_next_line.c				\
		main.c						\

BSRC =	get_next_line_utils_bonus.c		\
		get_next_line_bonus.c			\
		main.c	

OBJECTB = $(BSRC:.c=.o)
OBJECT = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
BUFFER = -D BUFFER_SIZE=
SIZE = 1000000


all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(BUFFER)$(SIZE) -o $(NAME)

bonus:
	$(CC) $(FLAGS) $(BSRC) $(BUFFER)$(SIZE) -o $(BNAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all
