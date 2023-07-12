/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:25:54 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/05 12:04:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_size;

	d_size = ft_strlen(dest);
	if (size <= d_size)
		return (ft_strlen(src) + size);
	while (*src && (d_size + 1 < size))
	{
		dest[d_size] = *src;
		d_size++;
		src++;
	}
	dest[d_size] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
