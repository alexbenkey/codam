
CC = gcc

NAME = libft.a

header = libft.h

OBJ = $(OBJ1:.o=.c)

OBJ1 = ft_memset.o ft_memcpy.o ft_memmove.o ft_putchar_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_tolower.o ft_toupper.o \
ft_strchr.o ft_strrchr.o ft_strlen.o ft_strnstr.o ft_memcmp.o ft_memchr.o ft_bzero.o ft_strncmp.o ft_strdup.o ft_strlcpy.o ft_strlcat.o ft_atoi.o \
ft_calloc.o ft_isalpha.o ft_isalnum.o ft_isdigit.o ft_isascii.o ft_isprint.o ft_strtrim.o ft_strmapi.o ft_substr.o ft_strjoin.o ft_itoa.o ft_split.o \
ft_striteri.o ft_arrextra.o ft_arrextra2.o ft_iswhite_space.o ft_strjoin3.o ft_strjoinx.o ft_atoi_l.o

BONES_OBJ = $(BONES_OBJ1:.o=.c)

BONES_OBJ1 = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o \
ft_lstascii.o ft_lstextra.o

CFLAGS = -Wall -Werror -Wextra -g

OBF_DIR= obj

ifdef plusbones
OBJ_FILES = $(OBJ:%.c=$(OBF_DIR)/%.o) $(BONES_OBJ:%.c=$(OBF_DIR)/%.o)
else
OBJ_FILES = $(OBJ:%.c=$(OBF_DIR)/%.o)
endif

all: $(NAME)

$(NAME): $(OBF_DIR) $(OBJ_FILES)
	ar -crs $@ $(OBJ_FILES)

$(OBF_DIR)/%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBF_DIR):
	mkdir $(OBF_DIR)

clean:
	rm -rf $(OBF_DIR)

fclean: clean
	rm -f $(NAME)

f: fclean

re:
	$(MAKE) fclean
	$(MAKE)

bonus:
	$(MAKE) plusbones=1

.PHONY: all clean fclean re f