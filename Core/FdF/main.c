/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 19:47:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/11/01 13:59:38 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "MLX42-master/include/MLX42/MLX42.h"
#include "FdF.h"

void	draw_vert_line(int height);
void	draw_horz_line(int size, int pos, int col);
void	line_move_horz(void);
int		draw_points(t_plist *top, int col);

mlx_image_t	*g_img;

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
// 	// draw_horz_line(20, 0, 120);
// 	// sleep(5);
// 	// draw_horz_line(20, 400, 120);
// }

void	hook(void *param)
{
	mlx_t		*mlx;
	static int	i = 0;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (g_img->instances[0].y >= 0 && i == 1)
	// 	g_img->instances[0].y -= 20;
	// if (g_img->instances[0].y == 1)
	// 	i = 0;
	// if (g_img->instances[0].y <= 600 && i == 0)
	// 	g_img->instances[0].y += 20;
	// if (g_img->instances[0].y == 560)
	// 	i = 1;
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	char	*str;
	t_plist	*top;
	int		i;

	top = get_map(argv[1]);
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	// while (top)
	// {
	// 	//ft_printf("coordinate %i: x: %i y: %i z: %i\n", i++, top->x, top->y, top->z);
	// 	mlx_put_pixel(g_img, (top->x * 5), (top->y * 5), 0);
	// 	top = top->next;
	// }
	draw_points(top, -120);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	draw_vert_line(int height)
{
	int	i;

	i = 0;
	while (i < WIDTH)
		mlx_put_pixel(g_img, i++, height, 120);
	return ;
}

void	draw_horz_line(int size, int pos, int col)
{
	int	width;
	int	starting_height;

	width = 0;
	starting_height = pos;
	while (pos < (starting_height + size))
	{
		while (width < WIDTH)
			mlx_put_pixel(g_img, width++, pos, col);
		width = 0;
		pos++;
	}
	return ;
}

int	draw_points(t_plist *top, int col)
{
	t_plist	*tmp;
	int		x;
	int		y;
	int		row;
	int		i;

	i = 1;
	row = 0;
	tmp = top;
	if (!top)
		return (0);
	while (tmp)
	{
		while (row == tmp->y && tmp)
		{
			x = ((WIDTH / 2) + (tmp->x * 2));
			y = ((y + 10) + (tmp->y * 2));
			if (x >= WIDTH || y >= HEIGHT)
				return (0);
			printf("point nr.: %i, row: %i, x: %i, y: %i\n", i, row, x, y);
			mlx_put_pixel(g_img, x, y, col);
			tmp = tmp->next;
			i++;
		}
		row += 1;
		y = row * 5;
	}
	return (0);
}

// void	line_move_horz(void)
// {
// 	int	height;
// 	int	size;

// 	size = 20;
// 	height = 0;
// 	//while (1)
// 	//{
// 		while (height < (HEIGHT - (size + 1)))
// 		{
// 			draw_horz_line(20, (height + 1), 120);
// 			draw_horz_line(1, height, -120);
// 			height++;
// 		}
// 		//draw_horz_line(3, 300, -128);
// 		// while (height > (0 + size))
// 		// {
// 		// 	draw_horz_line(20, height, 120);
// 		// 	draw_horz_line(1, (height + 1), 255);
// 		// 	height--;
// 		// }	
// 	//}
// }
