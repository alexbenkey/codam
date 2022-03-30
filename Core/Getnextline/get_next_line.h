#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *string);
int		check_malloc(char *mem);
char	*trim_start(char *buffer, int i);
char	*trim_end(char *buffer);
char	*gnl_memset(char *origin, char *destination);
int		check_for_nl(char *buffer);
char	*make_return(char *string, int end);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(char *mystring, size_t len);
int		get_len(char *str);

#endif