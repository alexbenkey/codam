# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbax <jbax@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/17 18:03:37 by jbax          #+#    #+#                  #
#    Updated: 2023/05/09 18:49:11 by avon-ben      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

VPATH= expander : executor : files : lexer : headers : parser

NAME= minishell

SRC= and_or_loop.c readline.c signals.c main.c pwd.c what_cmd.c ft_cd.c is_empty.c\
	echo.c export.c environment.c unset.c exit.c execve.c expander.c\
	envget.c letspipe.c heredoc.c openfiles.c wildcard.c expand_quotes.c expand_vars.c\
	split_not_quote.c\
	main_parser.c parse_quotes.c parsing_list.c syntax_checkers.c\
	parsing_tools.c tokanize_tools.c fill_node.c syntax_checker_tools.c\
	parse_splitter.c cutting_tools.c libft_variations.c memory_tools.c \
	mini_tokanizer.c parse_cleaner.c seeking_tools.c heredoc_wrap.c\
	splitting_tools.c transpose.c syntax_messaging.c parse_operators.c\
	internal_splitters.c simple_tools.c syntax_checker_main.c
	

wild= $(OBF_DIR)/envget.o $(OBF_DIR)/environment.o $(OBF_DIR)/expand_quotes.o $(OBF_DIR)/expand_vars.o\
 $(OBF_DIR)/wildcard.o $(OBF_DIR)/expander.o $(OBF_DIR)/exit.o $(OBF_DIR)/readline.o

OBF_DIR= OBF

OBF= $(SRC:%.c=$(OBF_DIR)/%.o)

HEADER= builtins_data_struct.h all.h structures.h

lib=libft/libft.a

CC= gcc

CFLAGS= -g -Wall -Wextra -Werror
# CFLAGS+= $(SAN)
# CFLAGS+= --coverage
CFLAGS+= -o

RLINE= -lreadline -L ~/.brew/opt/readline/lib/ $(lib)

SAN= -fsanitize=address

OO= -O3

# all:$(NAME)

all:
	@$(MAKE) $(NAME) -j4

a.out: $(OBF_DIR) $(wild)
	$(CC) $(CFLAGS) $@ $(wild) $(RLINE) 

$(NAME): $(OBF_DIR) $(OBF)
	$(CC) $(CFLAGS) $@ $(OBF) $(RLINE) 

$(OBF_DIR)/%o: %c $(HEADER) $(lib)
	$(CC) -c $(CFLAGS) $@ $< -I ~/.brew/opt/readline/include/ -I $(lib)

$(lib):
	$(MAKE) -C libft bonus

$(OBF_DIR):
	mkdir $(OBF_DIR)

clean:
	@rm -rf $(OBF) $(OBF_DIR)

fclean:
	@rm -rf $(OBF) $(OBF_DIR) $(NAME)
	$(MAKE) -C libft fclean

f: fclean

r:$(NAME)
	./$(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE) all

Norm: $(SRC) $(HEADER)
	norminette $^

.PHONY: all re fclean clean f norm
