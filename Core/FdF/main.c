/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 16:25:47 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/12/02 22:28:05 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	fdf_hook_key(mlx_key_data_t keydata, void *m_data)
{
	t_data	*data;	

	data = m_data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_RIGHT_BRACKET && keydata.action == MLX_PRESS)
		adjust_z_offset_increase(data);
	if (keydata.key == MLX_KEY_LEFT_BRACKET && keydata.action == MLX_PRESS)
		adjust_z_offset_decrease(data);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		adjust_pos_downward(data);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		adjust_pos_upward(data);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		adjust_pos_left(data);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		adjust_pos_right(data);
	if (keydata.key == MLX_KEY_KP_MULTIPLY && keydata.action == MLX_REPEAT)
		adjust_z_offset_mult(data);
	if (keydata.key == MLX_KEY_KP_DIVIDE && keydata.action == MLX_REPEAT)
		adjust_z_offset_devide(data);
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		zoom_in(data);
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		zoom_out(data);
}

int32_t	main(int argc, char **argv)
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_data			*data;
	int				col;

	data = malloc(sizeof (t_data));
	get_map(argv[1], data);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", 1);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	initialise(data, img, mlx);
	write_text(data);
	cover_image(data);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_lines(data);
	mlx_key_hook(data->mlx, &fdf_hook_key, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}

void	initialise(t_data *data, mlx_image_t *img, mlx_t *mlx)
{
	double	interval;

	interval = ((double)BUF_WIDTH * ((double)1 - ((double)1 / \
	(double)START_RATIO)));
	data->interval = (interval / (float)data->width);
	data->angle = ANGLE;
	data->mlx = mlx;
	data->img = img;
	data->start_x = (double)WIDTH / (double)START_RATIO;
	data->start_y = (double)20;
	data->current_x = data->start_x;
	data->current_y = data->start_y;
	data->next_x = data->start_x;
	data->next_y = data->start_y;
	data->z_offset = Z_OFFSET;
}

void	cover_image(t_data *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(data->img, x, y, 100);
			x++;
		}
		x = 0;
		y++;
	}
}
