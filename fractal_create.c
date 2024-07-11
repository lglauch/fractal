/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:24 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/14 15:58:31 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandel_real(int x, t_fractal *fractal)
{
	double	new_real;

	new_real = fractal->start_x + ((double)x / WIDTH)
		* (fractal->end_x - fractal->start_x);
	return (new_real);
}

double	mandel_img(int y, t_fractal *fractal)
{
	double	new_imag;

	new_imag = fractal->start_y + ((double)y / WIDTH)
		* (fractal->end_y - fractal->start_y);
	return (new_imag);
}

t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_pixel	pixel;
	int		iter;

	iter = is_mandelbrot(mandel_real(x, fractal), mandel_img(y, fractal),
			*fractal);
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
	{
		pixel.colour = 0x000000;
	}
	else
	{
		pixel.colour = colours(fractal, iter, pixel);
	}
	return (pixel);
}

t_pixel	make_julia(int x, int y, t_fractal *fractal, char **argv)
{
	t_pixel	pixel;
	int		iter;

	create_c_value(fractal, argv);
	fractal->x_julia = fractal->start_x + ((double)x / WIDTH)
		* (fractal->end_x - fractal->start_x);
	fractal->y_julia = fractal->start_y + ((double)y / HEIGHT)
		* (fractal->end_y - fractal->start_y);
	iter = is_julia(fractal->x_julia, fractal->y_julia,
			fractal->c_re_julia, fractal->c_im_julia);
	pixel.x = x;
	pixel.y = y;
	if (iter == MAX_ITER)
		pixel.colour = iter;
	else
	{
		pixel.colour = colours(fractal, iter, pixel);
	}
	return (pixel);
}

void	fractal_create(t_fractal *fractal, char **argv)
{
	u_int32_t		x;
	u_int32_t		y;
	t_pixel			pixel;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (!ft_compare_input(argv[1], "mandelbrot", 10))
				pixel = make_mandelbrot(x, y, fractal);
			else if (!ft_compare_input(argv[1], "julia", 5))
				pixel = make_julia(x, y, fractal, argv);
			if (x * fractal->zoom <= WIDTH && y * fractal->zoom <= HEIGHT)
			{
				mlx_put_pixel(fractal->img, pixel.x * fractal->x_offset,
					pixel.y * fractal->y_offset, pixel.colour);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
