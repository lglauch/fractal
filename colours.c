/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:11:08 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/13 17:41:02 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colours(t_fractal *fractal, int iter, t_pixel pixel)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (pixel.colour = 0x000000);
	if (fractal->key_data.key == MLX_KEY_9)
	{
		r = 50 + ((iter % 8) * 32 + fractal->mouse_x);
		g = 50 + (iter % 16) * 16 + fractal->mouse_y;
		b = 50 + (iter % 32) * 8 - fractal->mouse_x;
		return (pixel.colour = (b << 16) | (g << 8) | r);
	}
	else
	{
		r = (iter % 8) * 32;
		g = (iter % 16) * 16;
		b = (iter % 32) * 8;
		return (pixel.colour = (r << 16) | (g << 8) | b);
	}
}
