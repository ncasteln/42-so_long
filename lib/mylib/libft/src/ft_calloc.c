/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:27:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/07 12:28:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t n_bits)
{
	char	*p;
	size_t	total_size;

	total_size = len * n_bits;
	if (len && (total_size / len) != n_bits)
		return (NULL);
	p = malloc (total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
