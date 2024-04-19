# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 00:39:51 by alex              #+#    #+#              #
#    Updated: 2023/12/22 18:26:51 by avon-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=  Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
				   PresidentialPardonForm.cpp Intern.cpp

OBJ				= $(SRC:.cpp=.o)

COMP			= c++
FLAGS			= -g -Wall -Wextra -Werror -I. -fsanitize=address

NAME			= intern

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