# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 00:39:51 by alex              #+#    #+#              #
#    Updated: 2023/10/11 16:54:17 by avon-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= Zombie.cpp zombieHorde.cpp main.cpp 
OBJ				= $(SRC:.cpp=.o)

COMP			= c++
FLAGS			= -g -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= zombies

all:			$(NAME)

$(NAME):		$(OBJ)
				$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test