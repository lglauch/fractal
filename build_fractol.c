/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:00:41 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/14 13:54:11 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, "Fract'ol", false);
	if (!fractal->mlx_connection)
	{
		free(fractal);
		malloc_error();
	}
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_close_window(fractal->mlx_connection);
		free(fractal->mlx_connection);
		free(fractal);
		malloc_error();
	}
	fractal->argv = argv;
	fractal_create(fractal, argv);
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}
