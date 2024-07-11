/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morefunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:44:16 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/15 12:06:43 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *i)
{
	char	c;

	if (n >= 10)
		ft_putnbr_unsigned(n / 10, i);
	if (*i != -1)
	{
		c = (n % 10) + '0';
		if (write(1, &c, 1) == -1)
			*i = -1;
		else
			(*i)++;
	}
}

void	ft_puthexa_upper(uintptr_t n, int *i)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthexa_upper(n / 16, i);
		if (*i == -1)
			return ;
	}
	ft_putchar(hexa[n % 16], i);
	if (*i == -1)
		return ;
}

void	ft_check_write(const char *format, int *i)
{
	if (write(1, format, 1) == -1)
		*i = -1;
	else
		(*i)++;
}
