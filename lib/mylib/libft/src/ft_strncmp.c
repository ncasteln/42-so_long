/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:10 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/04 14:17:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	i = 0;
	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	while ((i < n) && (s1_ptr[i] == s2_ptr[i]))
	{
		if ((s1_ptr[i] == '\0') || (s2_ptr[i] == '\0'))
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1_ptr[i] - s2_ptr[i]);
}
