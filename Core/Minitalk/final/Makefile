NAME	=
CLIENT	=	client
SERVER	=	server

#libft variables
LIBFT	= src/libft/libft.a
LIBFT_DIR = src/libft

#ft_printf Variables:
LIBFTPRINTF	=	src/ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	src/ft_printf

#minitalk variables
SRC_C	=	client.c 
SRC_S	=	server.c
OBJ_S	=	server.o
OBJ_C	=	client.o 
#INC		=	minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

all: $(LIBFT) $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) #$(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(OBJ_C) #$(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re