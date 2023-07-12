/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_is_valid_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:38:18 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/07 10:39:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_is_valid_ext(const char *s, const char *ext)
{
	int	i;

	if (!s || !ext)
		return (0);
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == '.')
		{
			if (!(ft_strncmp(s + i, ext, ft_strlen(ext))))
				return (1);
		}
		i--;
	}
	return (0);
}
