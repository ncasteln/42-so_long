/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:31:22 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/04 08:57:43 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_hex(n / 16, uppercase);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
		{
			if (uppercase)
				ft_putchar(n + 55);
			else
				ft_putchar(n + 87);
		}
		len++;
	}
	return (len);
}

int	print_x(char type, va_list ap)
{
	if (type == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), 1));
	return (ft_putnbr_hex(va_arg(ap, unsigned int), 0));
}

int	print_p(va_list ap)
{
	ft_putstr("0x");
	return (ft_putnbr_hex((unsigned long) va_arg(ap, void *), 0) + 2);
}
