/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:33:36 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/15 12:30:34 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_format(const char *conversion, va_list args, int *i)
{
	int		m;

	m = 0;
	if (conversion[m] == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (conversion[m] == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (conversion[m] == 'p')
		ft_putpointer(va_arg(args, void *), i);
	else if (conversion[m] == 'd')
		ft_putnbr(va_arg(args, int), i);
	else if (conversion[m] == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (conversion[m] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), i);
	else if (conversion[m] == 'x')
		ft_puthexa(va_arg(args, unsigned int), i);
	else if (conversion[m] == 'X')
		ft_puthexa_upper(va_arg(args, unsigned int), i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar(*format++, &i);
			else
				ft_check_format(format++, args, &i);
		}
		else
			ft_check_write(format++, &i);
		if (i == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (i);
}
// #include <stdio.h>
// int main (void)
// {
// 	char str[20] = "54sdfdsf";
// 	printf("%x\n", -10);
// 	ft_printf("%x", -10);
// }
