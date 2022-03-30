NAME = 	CtF.out
SRC  = 	C_to_F.c			
LIB	 =	./libs/libft/libft.a
LIB_HEADERS = 	-I./libs/libft/
OBJECTS	=	$(SRC:.c=.o)
INCLUDE =	-I include $(LIB_HEADERS)
CFLAGS	=	-Wall -Wextra -Werror
CC    	=	gcc

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME):$(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) -o $(NAME) $(OBJECTS)
	@echo "made"

$(LIB):
	@$(MAKE) -s -C $(dir $(LIB))
	@echo "libft made"

fclean:
	rm -f $(NAME)

re: fclean all 

.PHONY: clean fclean re all
