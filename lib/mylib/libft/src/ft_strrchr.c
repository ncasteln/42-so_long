/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:23:05 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/04 14:00:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (c == '\0')
		return ((char *) str + ft_strlen(str));
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (*(str + i) == (char) c)
			return ((char *) str + i);
		i--;
	}
	return (NULL);
}
