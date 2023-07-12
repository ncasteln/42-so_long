/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:33:33 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/04 10:26:31 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_signed(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr_signed(n / 10);
			n = n % 10;
		}
		if (n < 10)
			ft_putchar(n + 48);
	}
}

static void	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + 48);
}

int	print_di(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_signed(n);
	return (get_digit_len(n));
}

int	print_u(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putnbr_unsigned(u);
	return (get_digit_len(u));
}
