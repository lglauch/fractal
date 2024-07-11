/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:38:18 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/22 15:01:53 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

void	ft_putchar(char c, int *i);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *i);
int		ft_putnbr(int n, int *i);
void	ft_putpointer(void *s, int *i);
int		ft_puthexa(uintptr_t n, int *i);
void	ft_putnbr_unsigned(unsigned int n, int *i);
void	ft_puthexa_upper(uintptr_t n, int *i);
int		ft_printf(const char *format, ...);
void	ft_check_format(const char *conversion, va_list args, int *i);
void	ft_check_write(const char *format, int *i);

#endif