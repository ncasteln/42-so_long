/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:58:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/03/29 12:29:18 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, s1_len);
	ft_memcpy(p + s1_len, s2, s2_len);
	*(p + s1_len + s2_len) = '\0';
	return (p);
}
