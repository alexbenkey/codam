/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 15:24:48 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/02 00:35:00 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // remove this
# include <fcntl.h> // and this
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *string);
int		check_malloc(char *mem);
int		count_nl(char *string);
char	*trim_start(char *buffer, int i);
char	*trim_end(char *buffer);
char	*gnl_memset(char *origin, char *destination);
int		check_for_nl(char *buffer);
char	*make_return(char *return_string);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(char *mystring, size_t len);
int		ft_strlen(char *str);
char	*ft_strjoin(char *destination, char *source);
int		check_for_newline_in_string(char *string);
int		ft_clear(void **ptr);
void	*ft_memset(char	*mystring, int c, size_t len);

#endif