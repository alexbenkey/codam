#include "FdF.h"

t_two_points	*store_2_points(int pt1_x, int pt1_y, int pt2_x, int pt2_y)
{
	t_two_points	*vals;

	vals = malloc(sizeof(t_two_points));
	if (pt1_x < pt2_x)
	{
		vals->x1 = pt1_x;
		vals->y1 = pt1_y;
		vals->x2 = pt2_x;
		vals->y2 = pt2_y;
	}
	else
	{
		vals->x1 = pt2_x;
		vals->y1 = pt2_y;
		vals->x2 = pt1_x;
		vals->y2 = pt1_y;
	}
	return (vals);
}

int	double_adjuster(float value)
{
	int	y;
	int	int_cpy;

	int_cpy = value;
	if ((value - int_cpy) >= 0.5)
		y = int_cpy + 1;
	else
		y = int_cpy;
	return (y);
}

float	get_gradient(t_two_points vals)
{
	float	x_dif;
	float	y_dif;
	float	gradient;

	x_dif = vals.x2 - vals.x1;
	y_dif = vals.y2 - vals.y1;
	if (x_dif == 0)
		return (x_dif);
	gradient = y_dif / x_dif;
	return (gradient);
}

void	draw_line(t_two_points vals, mlx_image_t *img)
{
	float	g;
	int		tmp_point_x;
	float	tmp_point_y;

	tmp_point_x = vals.x1;
	tmp_point_y = vals.y1;
	g = get_gradient(vals);
	while (tmp_point_x <= vals.x2)
	{
		if ((tmp_point_x < WIDTH) && (double_adjuster(tmp_point_y) < HEIGHT))
			mlx_put_pixel(img, tmp_point_x++, double_adjuster(tmp_point_y), \
			0xFFFFFF);
		tmp_point_y += g;
	}
}

void	draw_lines(t_plist *top, mlx_image_t *img)
{
	t_two_points	*line;
	t_plist			*tmp;

	tmp = top;
	while (tmp)
	{
		line = find_bottom_left(tmp);
		//printf("line points: x1: %d, y1: %d, x2: %d, y2: %d\n", line->x1, line->y1, line->x2, line->y2);
		if (line->x1 != -1)
			draw_line(*line, img);
		free(line);
		// line = find_bottom_right(tmp);
		// printf("line points: x1: %d, y1: %d, x2: %d, y2: %d\n", line->x1, line->y1, line->x2, line->y2);
		// if (line->x1 != -1)
		// 	draw_line(*line, img);
		// free(line);
		tmp = tmp->next;
	}
}
