/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:31:16 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/05 15:29:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;
	size_t	len;

	len = ft_strlen(str);
	p = malloc (len + 1);
	if (!p)
		return (0);
	ft_memcpy(p, str, len);
	*(p + len) = '\0';
	return (p);
}
