/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 19:47:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/11/07 23:54:56 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// void	hook(void *param)
// {
// 	mlx_t	*mlx;
// 	int 	i;

// 	i = 0;
// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }

void	hook(void *param)
{
	mlx_t		*mlx;
	static int	i = 0;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int32_t	main(int argc, char **argv)
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_plist			*top;
	int				i;
	int				col;

	top = get_map(argv[1]);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "test", 1);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 0, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
	set_coordinates(top);
	//print_vals(top);
	i = draw_grid(top, img);
	draw_lines(top, img);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	draw_grid(t_plist *top, mlx_image_t *img)
{
	int	i;
	int	col_val;

	col_val = 255;
	while (top)
	{
		if (top->z == 0)
			mlx_put_pixel(img, top->c_x, top->c_y, 0xFFFFFF);
		else
		{
			mlx_put_pixel(img, top->c_x, (top->c_y - (top->z * 3)), \
			(0xFFFFFF));
		}
		top = top->next;
		++i;
	}
	return (i);
}

int	get_r(int rgba)
{
    // Move 3 bytes to the right and mask out the first byte.
    return ((rgba >> 24) & 0xFF);
}

void	set_coordinates(t_plist *top)
{
	int	diag;
	int	top_x;
	int	top_y;

	top->c_x = WIDTH / 2;
	top->c_y = (HEIGHT - BUF_HEIGHT) / 2;
	top_x = top->c_x;
	top_y = top->c_y;
	if (wider_or_taller(top))
		diag = get_interval_width(top);
	else
		diag = get_interval_height(top);
	//exit (0);
	set_first_node(top);
	while (top->next)
	{
		if (top->next->i_y == top->i_y)
		{
			top->next->c_y = top->c_y + diag;
			top->next->c_x = top->c_x + diag;
		}
		else
		{
			top_x = top_x - diag;
			top_y = top_y + diag;
			top->next->c_x = top_x;
			top->next->c_y = top_y;
		}
		top = top->next;
	}
}

// returns 1 if the grid is wider than taller, otherwise returns 0
int	wider_or_taller(t_plist *top)
{
	t_plist	*tmp;

	tmp = top;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->i_x > tmp->i_y)
		return (1);
	return (0);
}

int get_interval_width(t_plist *top)
{
	t_plist	*tmp;
	int		number;
	int		width;

	tmp = top;
	while (tmp->next->i_y != (tmp->i_y + 1))
	{
		//printf("x: %i", tmp->i_x);
		tmp = tmp->next;
	}
	number = tmp->i_x;
	width = ((WIDTH / 2) - ((WIDTH - BUF_WIDTH) / 2)) / number;
	return (width);
}

int get_interval_height(t_plist *top)
{
	t_plist	*tmp;
	int		number;
	int		height;

	tmp = top;
	while (tmp)
		tmp = tmp->next;
	number = tmp->i_x + tmp->i_y;
	height = BUF_HEIGHT / number;
	return (height);
}

void set_first_node(t_plist *top)
{
	top->c_x = WIDTH / 2;
	top->c_y = (HEIGHT - BUF_HEIGHT) / 2;
}

void print_vals(t_plist *top)
{	
	int	i;

	i = 0;
	while (top)
	{
		printf("node: %i, i_x: %i, i_y: %i, x: %i, y: %i, z: %i\n", i, \
		top->i_x, top->i_y, top->c_x, top->c_y, top->z);
		top = top->next;
		i++;
	}
}

// t_two_points	*find_bottom_left(t_plist *top)
// {
// 	t_plist			*tmp;
// 	t_two_points	line;
// 	int				next_x;
// 	int				next_y;
// 	int				i;

// 	i = 0;
// 	tmp = top;
// 	while (tmp->next->i_y != (tmp->i_y + 1))
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	if (tmp->next->i_y == tmp->i_y + 1)
// 	{
// 		printf("found node: %i, i_x: %i, i_y: %i, x: %i, y: %i, z: %i\n", i, \
// 		tmp->i_x, tmp->i_y, tmp->c_x, tmp->c_y, tmp->z);
// 		next_x = tmp->next->c_x;
// 		next_y = tmp->next->c_y;
// 	}
// 	return (store_2_points(top->c_x, top->c_y, next_x, next_y));
// }

t_two_points	*find_bottom_left(t_plist *top)
{
	static int		current_x = -1;
	static int		current_y = -1;
	int				c_x;
	int				c_y;

	if (current_x == -1)
	{
		current_x = top->i_x;
		current_y = top->i_y;
	}
	else
	{
		printf("current_x: %d, current_y: %d, top->i_x: %d, top->i_y: %d\n", current_x, current_y, top->i_x, top->i_y);
		while (current_x != top->i_x && current_y != top->i_y)
			top = top->next;
	}
	current_x = top->i_x;
	current_y = top->i_y;
	c_x = top->c_x;
	c_y = top->c_y;
	while (top)
	{
		if (top->i_x == current_x && (current_y + 1) == top->i_y)
			return (store_2_points(top->c_x, top->c_y, c_x, c_y));
		top = top->next;
	}
	return (store_2_points(-1, -1, -1, -1));
}

t_two_points *find_bottom_right(t_plist *top)
{
	static int		current_x = -1;
	static int		current_y = -1;

	if (current_x == -1)
	{
		current_x = top->i_x;
		current_y = top->i_y;
	}
	if (!top->next)
		return (store_2_points(-1, -1, -1, -1));
	else
	{
		while (current_x != top->i_x && current_y != top->i_y)
			top = top->next;
	}
	current_x = top->i_x;
	current_y = top->i_y;
	if (top->i_y == top->next->i_y)
	{
		printf("current_x: %d, current_y: %d, top->i_x: %d, top->i_y: %d\n", current_x, current_y, top->next->i_x, top->next->i_y);
		return (store_2_points(top->c_x, top->c_y, top->next->c_x, top->next->c_y));
	}
	return (store_2_points(-1, -1, -1, -1));
}