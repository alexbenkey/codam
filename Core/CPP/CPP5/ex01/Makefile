# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 00:39:51 by alex              #+#    #+#              #
#    Updated: 2023/11/09 21:01:37 by avon-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=  Bureaucrat.cpp Form.cpp main.cpp
OBJ				= $(SRC:.cpp=.o)

COMP			= c++
FLAGS			= -g -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= bureacrat

all:			$(NAME)

%.o:%.cpp
				$(COMP) -c $(FLAGS) -o $@ $<

$(NAME):		$(OBJ)
				$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test