/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:11:14 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/15 12:06:31 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		*i = -1;
	else
		(*i)++;
}

void	ft_putstr(char *s, int *i)
{
	char	*str;

	str = s;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str++, i);
		if (*i == -1)
			return ;
	}
}

int	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (*i = -1);
		return (*i += 11);
	}
	if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (*i = -1);
		n = -n;
		*i += 1;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, i) == -1)
			return (*i = -1);
	}
	ft_putchar(n % 10 + '0', i);
	return (*i);
}

void	ft_putpointer(void *s, int *i)
{
	uintptr_t	address;

	address = (uintptr_t) s;
	if (write (1, "0x", 2) == -1)
		*i = -1;
	else
		*i += 2;
	if (*i != -1)
		ft_puthexa(address, i);
}

int	ft_puthexa(uintptr_t n, int *i)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexa(n / 16, i);
		if (*i == -1)
			return (*i = -1);
	}
	ft_putchar(hexa[n % 16], i);
	if (*i == -1)
		return (*i = -1);
	return (*i + 1);
}
