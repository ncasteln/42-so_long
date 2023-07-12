/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:24:25 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/04 15:21:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	size_t	s_size;

	i = 0;
	s_size = ft_strlen(src);
	if (d_size > 0)
	{
		while ((i < s_size) && (i < d_size - 1))
		{
			if (src[i])
				dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s_size);
}
