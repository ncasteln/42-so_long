/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:29:30 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/05 18:00:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char *p, int n, int sign, size_t len)
{
	size_t	i;

	i = 0;
	if (n == 0)
		p[0] = '0';
	if (sign == -1)
	{
		p[i] = '-';
		i++;
	}
	p[len] = '\0';
	while (n > 0)
	{
		p[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

static	int	get_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	char	*p;

	p = NULL;
	sign = 1;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		if (n < 0)
		{
			sign = -1;
			n = n * -1;
			len++;
		}
		len += get_length(n);
		p = malloc ((len + 1) * sizeof(char));
		if (!p)
			return (NULL);
		fill(p, n, sign, len);
	}
	return (p);
}
