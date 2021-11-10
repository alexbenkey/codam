#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>

size_t		ft_strlen(const char *string);
int			ft_printf(const char *str, ...);
int			ft_isprint(unsigned int input);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar(char c);
void		ft_putnbr_fd(int n, int fd);
int			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		printhex(long n, char c);

#endif