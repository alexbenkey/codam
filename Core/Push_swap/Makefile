NAME = 	ps.out
SRC  = 	main.c				\
LIB	 =	./src/libft/libft.a
LIB_HEADERS = 	-I./libs/libft/
OBJECTS	=	$(SRC:.c=.o)
INCLUDE =	-I include $(LIB_HEADERS)
FLAGS = -Wall -Werror -Wextra 
CC    	=	gcc


all: $(NAME)

$(NAME):$(OBJECTS) $(LIB)
	$(CC) $(FLAGS) $(INCLUDE) $(LIB) -o $(NAME) $(OBJECTS)
	@echo "made man"

$(LIB):
	@$(MAKE) -s -C $(dir $(LIB))
	@echo "libft made"

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) 

re: fclean all 

.PHONY: clean fclean re all