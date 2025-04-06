/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/06 16:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	numof_arg(const char *format)
// {
// 	int	i;
// 	int	j;
// 	char	c;

// 	i = 0;
// 	j = 0;
// 	while (format[i])
// 	{
// 		c = format[i + 1];
// 		if (format[i] == '%' && c == 'c' && c == 's' && c == 'p' && c == 'd'
// 			&& c == 'i' && c == 'u' && c == 'x' && c == 'X' && c == '%')
// 		{
// 			j++;
// 			i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (i);
// }

int	is_data(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list args;

	va_start(args, format);
	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] != '%' || (format[i] == '%' && is_data(format[i + 1]) == 0))
		{
			if (format[i] == '%' && is_data(format[i + 1]) == )
				i++;
			ft_putchar(format[i]);
			i++;
		}
		else
		{
			if (format[i + 1] == 'c')
				ft_putchar(va_arg(args, int));
			if (format[i + 1] == 's')
				ft_putstr(va_arg(args, char *));
			// if (format[i + 1] == 'p')
			// 	ft_putchar(va_arg(args, char));
			if (format[i + 1] == 'd')
				ft_putnbr(va_arg(args, int));
			if (format[i + 1] == 'i')
				ft_putnbr(va_arg(args, int));
			if (format[i + 1] == 'u')
				ft_putnbr(va_arg(args, int));
			// if (format[i + 1] == 'x')
			// 	ft_puthex_upper(va_arg(args, unsigned int));
			// if (format[i + 1] == 'X')
				ft_putchar(va_arg(args, unsigned int));
			if (format[i + 1] == '%')
				ft_putchar('%');
			i = i + 2;
		}
	}
	va_end(args);
	return ((int)ft_strlen(format));
}
