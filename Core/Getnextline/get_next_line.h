#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *string);
char	*get_next_line(int fd);
int		get_line_length(int fd);
int		get_buf_len(char *string);
char	*split_nl(char *buffer, int buf_size, int *i);

#endif