NAME= philosophers

SRC= main.c parser.c utils.c atoi.c generation.c actions.c

OBF_DIR= OBF

OBF= $(SRC:%.c=$(OBF_DIR)/%.o)

HEADER= philosophers.h

CC= gcc

CFLAGS= -g -Wall -Wextra -Werror
CFLAGS+= $(SAN)
# CFLAGS+= --coverage
CFLAGS+= -o

SAN= -fsanitize=thread

OO= -O3

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBF_DIR) $(OBF)
	$(CC) $(CFLAGS) $@ $(OBF)

$(OBF_DIR)/%o: %c $(HEADER)
	$(CC) -c $(CFLAGS) $@ $<

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

norm: $(SRC) $(HEADER)
	norminette $^

.PHONY: all re fclean clean f norm

