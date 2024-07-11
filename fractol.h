/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:17:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/27 14:28:16 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 30

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mandelbrot
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	int		iter;
}			t_mandelbrot;

typedef struct s_julia
{
	double	z_re;
	double	z_im;
	int		iter;
}			t_julia;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	colour;
}		t_pixel;

typedef struct s_fractal
{
	void			*mlx_connection;
	void			*mlx_window;
	mlx_image_t		*img;
	double			zoom;
	int				offset_x;
	int				offset_y;
	char			**argv;
	int				mouse_x;
	int				mouse_y;
	double			c_re_julia;
	double			c_im_julia;
	bool			checker;
	bool			params_set;
	double			x_offset;
	double			y_offset;
	double			x_julia;
	double			y_julia;
	double			start_x;
	double			end_x;
	double			start_y;
	double			end_y;
	mlx_key_data_t	key_data;
}			t_fractal;

void	fractal_init(t_fractal *fractal, char **argv);
void	fractal_create(t_fractal *fractal, char **argv);
t_pixel	make_mandelbrot(int x, int y, t_fractal *fractal);
t_pixel	make_julia(int x, int y, t_fractal *fractal, char **argv);
int		is_mandelbrot(double x, double y, t_fractal fractal);
int		is_julia(double x, double y, double c_re, double c_im);

//helper
int		ft_compare_input(const char *s1, const char *s2, size_t n);
int		check_julia(int argc, char **argv);
void	clear_image(t_fractal fractal);
int		colours(t_fractal *fractal, int iter, t_pixel pixel);
void	create_c_value(t_fractal *fractal, char **argv);
double	ft_ctod(const char *str);

//hooks
void	close_func(mlx_key_data_t key_data, void *param);
void	my_scroll_func(double xdelta, double ydelta, void *param);
void	get_cursor_position(void *param);

#endif