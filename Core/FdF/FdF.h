/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 22:34:44 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/30 01:33:57 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_plist
{
	int					x;
	int					y;
	int					z;
	struct s_plist		*next;
}	t_plist;

# include "MLX42-master/include/MLX42/MLX42.h"
# include "src/ft_printf/ft_printf.h"
# include "src/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# define WIDTH 800
# define HEIGHT 600
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*check_block(char *lo, int r);
int		read_from_buf(int fd, char **leftovers);
int		ft_clear(void **ptr);
int		gnl_strchr(const char *s, int c);
t_plist	*get_map(char *map);
t_plist	*fill_list(t_plist *top, char **points, int y);
void	error_exit(void);
t_plist	*fdf_lstnew(int x, int y, int z);
void	fdf_lstadd_back(t_plist **lst, t_plist *new);

#endif