NAME = 	CtF.out
SRC  = 	C_to_F.c			
LIB	 =	./libs/libft/libft.a
LIB_HEADERS = 	-I./libs/libft/
OBJECTS	=	$(SRC:.c=.o)
INCLUDE =	-I include 
CFLAGS	=	-Wall -Wextra -Werror
CC    	=	gcc

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(LIB):
	@$(MAKE) -s -C $(dir $(LIB))
	@echo "libft made"

$(NAME):$(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) -o $(NAME) $(OBJECTS)
	@echo "made"

fclean:
	rm -f $(NAME)

re: fclean all 

.PHONY: clean fclean re all
