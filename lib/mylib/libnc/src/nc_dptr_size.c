/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dptr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:31:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/07 15:46:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_dptr_size_y(char **s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	return (y);
}

/* Returns the size of the items pointed by the pointers pointed by the dptr,
only if they have the same size, otherwise returs (-1) */
int	nc_dptr_size_x(char **s)
{
	int	i;
	int	j;
	int	size_x;

	i = 0;
	size_x = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
			j++;
		if (i == 0)
			size_x = j;
		if ((i > 0) && (size_x != j))
			return (-1);
		i++;
	}
	return (size_x);
}
