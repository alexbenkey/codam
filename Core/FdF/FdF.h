/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 22:34:44 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/11/04 20:57:31 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42-master/include/MLX42/MLX42.h"
# include "src/ft_printf/ft_printf.h"
# include "src/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# define WIDTH 800
# define HEIGHT 800
# define BUF_WIDTH 720
# define BUF_HEIGHT 720
# define BUFFER_SIZE 100

typedef struct s_plist
{
	int					i_x;
	int					i_y;
	int					c_x;
	int					c_y;
	int					z;
	struct s_plist		*next;
}	t_plist;

typedef struct s_two_points
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}	t_two_points;

char			*get_next_line(int fd);
char			*check_block(char *lo, int r);
int				read_from_buf(int fd, char **leftovers);
int				ft_clear(void **ptr);
int				gnl_strchr(const char *s, int c);
t_plist			*get_map(char *map);
t_plist			*fill_list(t_plist *top, char **points, int y);
void			error_exit(void);
t_plist			*fdf_lstnew(int x, int y, int z);
void			fdf_lstadd_back(t_plist **lst, t_plist *new);
int				double_adjuster(float value);
float			get_gradient(t_two_points vals);
t_two_points	*store_2_points(int pt1_x, int pt1_y, int pt2_x, int pt2_y);
void			draw_line(t_two_points vals, mlx_image_t *img);
int				wider_or_taller(t_plist *top);
int				get_interval_width(t_plist *top);
int				get_interval_height(t_plist *top);
void			set_first_node(t_plist *top);
void			set_coordinates(t_plist *top);
int				draw_grid(t_plist *top, mlx_image_t *img);
void			print_vals(t_plist *top);
int				get_r(int rgba);
void			draw_lines(t_plist *top, mlx_image_t *img);
t_two_points	*find_bottom_left(t_plist *top);
t_two_points 	*find_bottom_right(t_plist *top);

#endif