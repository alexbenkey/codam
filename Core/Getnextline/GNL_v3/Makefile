NAME = gnl.out
SRC =	get_next_line_utils.c		\
	  	get_next_line.c				\
		main.c						\

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
BUFFER = -D BUFFER_SIZE=
SIZE = 42

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(BUFFER)$(SIZE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
