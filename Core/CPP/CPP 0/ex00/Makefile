# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alex <alex@student.42.fr>                    +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/09 00:39:51 by alex          #+#    #+#                  #
#    Updated: 2023/07/05 18:55:54 by avon-ben      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC				= megaphone.cpp
OBJ				= $(SRC:.cpp=.o)

COMP			= c++
FLAGS			= -Wall -Wextra -Werror -I.

NAME			= megaphone

all:			$(NAME)

$(NAME):		$(OBJ)
				$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test