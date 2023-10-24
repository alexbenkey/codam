# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 00:39:51 by alex              #+#    #+#              #
#    Updated: 2023/10/03 13:03:32 by avon-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp 
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