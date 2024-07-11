/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:32:34 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/18 15:38:46 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_compare_input(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			len_1;
	int			len_2;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!s1 && !s2 && n == 0)
		return (0);
	if (len_1 != len_2)
		return (1);
	while ((((unsigned char *)s1)[i] != 0 || ((unsigned char *)s2)[i] != 0)
		&& i + 1 < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break ;
		i++;
	}
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

int	check_julia(int argc, char **argv)
{
	int		i;
	int		j;

	j = 2;
	if (argc == 4 && !ft_compare_input(argv[1], "julia", 5))
	{
		while (j < 4)
		{
			i = 0;
			while (argv[j][i] != '\0')
			{
				if (argv[j][i] == ',')
					return (1);
				if (argv[j][i] == '-' ||
					argv[j][i] == '+' || argv[j][i] == '.')
					i++;
				if (argv[j][i] != 0 && ft_isdigit(argv[j][i]) == 0)
					return (1);
				i++;
			}
			j++;
		}
		return (0);
	}
	return (1);
}

void	clear_image(t_fractal fractal)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(fractal.img, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_c_value(t_fractal *fractal, char **argv)
{
	if (fractal->params_set == false)
	{
		fractal->c_re_julia = ft_ctod(argv[2]);
		fractal->c_im_julia = ft_ctod(argv[3]);
		fractal->mouse_x = ft_ctod(argv[2]);
		fractal->mouse_y = ft_ctod(argv[3]);
	}
	else
	{
		fractal->c_re_julia = fractal->mouse_x / 1000.0;
		fractal->c_im_julia = fractal->mouse_y / 1000.0;
	}
}
