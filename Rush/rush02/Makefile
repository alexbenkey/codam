NAME  = rush02

#define variable named SRC that takes all of the .c files that I want to compile. (in this case main.c is in the current directory.)
#if you need multiple lines you can use: " \ " 
SRC = main.c

#first rule that takes the name of the program (rush02) 
all: $(NAME)

#this convention will allow for calling the rule that will launch the compilation
$(NAME):
	@gcc -o $(NAME) $(SRC)

#remove all the files.o but keep the executable file
clean:
	@/bin/rm -f *.o

#clean all file.o's and also the executable
fclean: clean
	@/bin/rm -f $(NAME)

#remove the previously compiled files and recompile the executable and all other output files
re: fclean all
