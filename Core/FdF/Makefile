NAME	=	FdF

#MLX variables
MLX		= MLX42-master/libmlx42.a
MLX_DIR = MLX42-master
MLX_SRX = MLX42-master/include/*

#libft variables
LIBFT	= src/libft/libft.a
LIBFT_DIR = src/libft

#ft_printf Variables:
LIBFTPRINTF	=		src/ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	src/ft_printf

#FdF variables
SRC	= 	main.c			\
		gnl.c 			\
		input_parser.c

OBJ =	$(SRC:.c=.o)
#INC	=	Fdf.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCLUDE     =   -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
RM			=	rm -rf

all: $(LIBFT) $(LIBFTPRINTF) $(MLX) $(NAME) 

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(INCLUDE) $(INC) $(LIBFT) $(LIBFTPRINTF) $(OBJ) $(MLX) -o $@ 
	@printf "$(_SUCCESS) FdF ready.\n"
#$(OBJ)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@ $(MAKE) -C $(MLX_DIR)

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	@ $(MAKE) clean -C $(MLX_DIR)
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ $(RM) $(OBJ)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) clean -C $(MLX_DIR)
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) FdF removed.\n"


re: fclean all

.PHONY: all clean fclean re