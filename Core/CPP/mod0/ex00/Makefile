NAME= megaphone

SRC= megaphone.cpp

OBF_DIR= OBF

OBF= $(SRC:%.cpp=$(OBF_DIR)/%.opp)

HEADER= megaphone.hpp

CC= c++

CPPFLAGS= -g -Wall -Wextra -Werror -std=c++98
# CFLAGS+= $(SAN)
# CFLAGS+= --coverage
CFLAGS+= -o

SAN= -fsanitize=address

OO= -O3

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBF_DIR) $(OBF)
	$(CC) $(CPPFLAGS) $@ $(OBF)

$(OBF_DIR)/%o: %c $(HEADER)
	$(CC) -c $(CPPFLAGS) $@ $<

$(OBF_DIR):
	mkdir $(OBF_DIR)

clean:
	@rm -rf $(OBF) $(OBF_DIR)

fclean:
	@rm -rf $(OBF) $(OBF_DIR) $(NAME)
	@rm -rf $(NAME)

r:$(NAME)
	./$(NAME)

re: fclean
	@$(MAKE)

	norminette $^

.PHONY: all re fclean clean f norm

