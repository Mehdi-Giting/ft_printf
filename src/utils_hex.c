/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:44:57 by marvin            #+#    #+#             */
/*   Updated: 2025/04/06 16:44:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int		ft_puthex(unsigned int n, const char format)
{
	int	count;
	char	*tab;

	count = 0;
	if (format == 'x')
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	while (n > 0)
	{
		if (n > 16)
		{
			count += ft_putchar(tab[n / 16]);
			n = n % 16;
		}
		else
		{
			count += ft_putchar(tab[n]);
			n = 0;
		}
	}
	return (count);
}
