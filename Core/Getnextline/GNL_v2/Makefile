# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avon-ben <avon-ben@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/06 15:24:39 by avon-ben      #+#    #+#                  #
#    Updated: 2022/02/27 23:56:01 by avon-ben      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = gnl.out
SRC =	get_next_line.c				\
		get_next_line_utils.c		\
		main.c						\

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g
BUFFER = -D BUFFER_SIZE=
SIZE = 1
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(BUFFER)$(SIZE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
