/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:16 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/18 14:53:54 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_func(mlx_key_data_t key_data, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key_data.key == 256)
	{
		free(fractal);
		mlx_terminate(fractal->mlx_connection);
		exit(EXIT_SUCCESS);
	}
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_REPEAT)
	{
		fractal->checker = true;
		fractal->params_set = true;
	}
	else
		fractal->checker = false;
	if (key_data.key == MLX_KEY_9)
		fractal->key_data = key_data;
}

void	zoom(t_fractal *fractal, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractal->start_x + ((double)x / WIDTH)
		* (fractal->end_x - fractal->start_x);
	y_math = fractal->start_y + ((double)y / HEIGHT)
		* (fractal->end_y - fractal->start_y);
	new_x_range = (fractal->end_x - fractal->start_x) / zoom_factor;
	new_y_range = (fractal->end_y - fractal->start_y) / zoom_factor;
	fractal->start_x = x_math - ((double)x / WIDTH) * new_x_range;
	fractal->end_x = fractal->start_x + new_x_range;
	fractal->start_y = y_math - ((double)y / HEIGHT) * new_y_range;
	fractal->end_y = fractal->start_y + new_y_range;
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		zoom_factor;

	(void)xdelta;
	fractal = (t_fractal *)param;
	if (fractal == NULL || fractal->argv == NULL)
		return ;
	mlx_get_mouse_pos(fractal->mlx_connection,
		&mouse_x, &mouse_y);
	zoom_factor = 1.5;
	if (ydelta < 0)
		zoom(fractal, mouse_x, mouse_y, 1 / zoom_factor);
	else if (ydelta > 0)
		zoom(fractal, mouse_x, mouse_y, zoom_factor);
	clear_image(*fractal);
	fractal_create(fractal, fractal->argv);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

void	get_cursor_position(void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = (t_fractal *)param;
	x = fractal->mouse_x;
	y = fractal->mouse_y;
	if (fractal->checker == false)
		return ;
	mlx_get_mouse_pos(fractal->mlx_connection,
		&fractal->mouse_x, &fractal->mouse_y);
	if (fractal->checker == true && (fractal->mouse_x != x
			|| fractal->mouse_y != y))
	{
		clear_image(*fractal);
		fractal_create(fractal, fractal->argv);
		mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
	}
}
