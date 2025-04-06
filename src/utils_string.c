/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:38:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/06 16:38:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln = ln * -1;
	}
	if (ln > 9)
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
	else
		ft_putchar((ln % 10) + '0');
}
