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
SRC	= 	input_parser.c							\
		main.c									\
		tools.c									\
		utils.c									\
		draw_lines.c							\
		adjusters.c								\
		adjusters_2.c							\
		draw_line_tools.c 						\
		draw_tools.c 							\
		manipulators.c 							\
		setters.c 								\
		z_interpreter.c 						\
		zoom_adjusters.c						\
		src/GNL/regular/get_next_line.c			\
		src/GNL/regular/get_next_line_utils.c	

OBJ =	$(SRC:.c=.o)
//INC	=	Fdf.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
BUFSIZE		=	-D BUFFER_SIZE = 10
INCLUDE     =   -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -g
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