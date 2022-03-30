/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 21:25:22 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/03/09 13:15:13 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_clear(void **ptr);
char	*ft_strdup(const char *s);
int		read_from_buf(int fd, char **leftovers);
char	*check_block(char *lo, int r);
void	*ft_calloc(size_t nelem, size_t elsize);

#endif