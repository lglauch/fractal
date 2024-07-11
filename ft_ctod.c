/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:51:13 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/18 14:06:50 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	skip_spaces(const char **str)
{
	while (**str && **str == ' ')
		(*str)++;
}

double	parse_integer(const char **str, int *sign)
{
	double	integerpart;

	integerpart = 0.0;
	if (**str == '-')
	{
		*sign = -1;
		++(*str);
	}
	while (**str >= '0' && **str <= '9')
	{
		integerpart = integerpart * 10.0 + (**str - '0');
		++(*str);
	}
	return (integerpart);
}

double	parse_fraction(const char **str)
{
	double	fractionpart;
	int		divisor_fraction;

	divisor_fraction = 1;
	fractionpart = 0.0;
	if (**str == '.')
	{
		++(*str);
		while (**str >= '0' && **str <= '9')
		{
			fractionpart = fractionpart * 10.0 + (**str - '0');
			divisor_fraction *= 10;
			++(*str);
		}
	}
	return (fractionpart / divisor_fraction);
}

double	ft_ctod(const char *str)
{
	int		sign;
	double	integerpart;
	double	fractionpart;

	sign = 1;
	skip_spaces(&str);
	integerpart = parse_integer(&str, &sign);
	fractionpart = parse_fraction(&str);
	return (sign * (integerpart + fractionpart));
}
