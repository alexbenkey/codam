/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 22:34:44 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 21:52:23 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42-master/include/MLX42/MLX42.h"
# include "src/ft_printf/ft_printf.h"
# include "src/GNL/regular/get_next_line.h"
# include "src/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>

// defines----------------------/

# define WIDTH 1600
# define HEIGHT 1100
# define BUF_WIDTH 1200
# define BUF_HEIGHT 800
# define BUFFER_SIZE 100
# define ANGLE 28
# define START_RATIO 2.0
# define PI 3.1415926
# define Z_OFFSET 2
# define TXT_HGT 150
# define T_INT 15

// structs---------------------/

typedef struct s_data
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	int				**points;
	int				height;
	int				width;
	double			interval;
	double			angle;
	double			zoom;
	double			current_x;
	double			current_y;
	double			start_x;
	double			start_y;
	double			next_x;
	double			next_y;
	double			z_offset;
}	t_data;

typedef struct s_two_points
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}	t_two_points;

// adjusters.c-----------------------------------------------------------/

void			adjust_right(t_data *data);
void			adjust_left(t_data *data);
void			adjust_reset(t_data *data);
void			adjust_x(t_data *data, char dir);
void			adjust_y(t_data *data, char dir);

// adjusters_2.c----------------------------------------------------------/

void			adjust_z_offset_increase(t_data *data);
void			adjust_z_offset_decrease(t_data *data);
void			adjust_z_offset_mult(t_data *data);
void			adjust_z_offset_devide(t_data *data);

// draw_line_tools.c------------------------------------------------------/

double			get_gradient(t_two_points *ttp);
void			switch_c(t_two_points *ttp);
void			re_init(t_data *data, t_two_points *ttp);
void			draw_line_x_base(t_data *data, t_two_points *ttp, double g);
void			draw_line_y_base(t_data *data, t_two_points *ttp, double g);

// draw_lines-------------------------------------------------------------/

void			draw_lines(t_data *data);
void			draw_vert_lines(t_data *data, t_two_points *ttp);
void			draw_hor_lines(t_data *data, t_two_points *ttp);
void			draw_line(t_data *data, t_two_points *ttp, double gradient);

// draw_tools.c-----------------------------------------------------------/

void			draw_wrapper_pix(t_data *data, double x, double y);
void			next_to_next_column_x(t_data *data, int i);
void			next_to_next_row_x(t_data *data, int i);
void			next_to_next_column_y(t_data *data, int i);
void			next_to_next_row_y(t_data *data, int i);

// input parser----------------------------------------------------------/

t_data			*get_map(char *path, t_data *data);
void			put_map_data(char *line, t_data *data, int y);
void			add_row(t_data *data, int y, int len);
void			error_exit(void);
int				get_len(char **splitted);

// main-------------------------------------------------------------------/

void			fdf_hook_key(mlx_key_data_t keydata, void *m_data);
void			initialise(t_data *data, mlx_image_t *img, mlx_t *mlx);
void			cover_image(t_data *data);

// manipulators.c---------------------------------------------------------/
void			adjust_pos_downward(t_data *data);
void			adjust_pos_upward(t_data *data);
void			adjust_pos_left(t_data *data);
void			adjust_pos_right(t_data *data);

// setters.c--------------------------------------------------------------/

void			set_next_to_current(t_data *data);
void			set_current_to_start(t_data *data);
void			set_current_to_next(t_data *data);

// tools.c----------------------------------------------------------------/

void			print_map(t_data *data);
void			update_coordinates_x(t_data *data, int i);
void			update_coordinates_y(t_data *data, int i);
void			write_text(t_data *data);

// utils------------------------------------------------------------------/
int				has_char(char *str, char c);
int				get_z_val(char *line);
void			free_splitted(char **spl);
unsigned int	double_adjuster(float value);
void			free_all(t_data *data);

// z_interpreters.c-------------------------------------------------------/

void			adjust_for_z_x(t_data *data, t_two_points *ttp, int i);
void			adjust_for_z_y(t_data *data, t_two_points *ttp, int i);

// zoom_adjusters.c-----------------------------------------------------/

void			zoom_in(t_data *data);
void			zoom_out(t_data *data);

#endif