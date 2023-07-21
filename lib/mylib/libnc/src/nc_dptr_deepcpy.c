/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dptr_deepcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:27:11 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 13:42:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static char	**allocate_lines(int y)
{
	char	**dst;

	dst = NULL;
	if (y)
		dst = malloc (sizeof(char *) * (y + 1));
	if (!dst)
		return (NULL);
	return (dst);
}

/* Make a deepcpy of a dptr whose ptrs has a variable length (the whole
structure is not necessary a rectangle) */
char	**nc_dptr_deepcpy(char **src)
{
	char	**dst;
	int		i;
	int		j;

	dst = allocate_lines(nc_dptr_size_y(src));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = malloc (sizeof(char) * (ft_strlen(src[i]) + 1));
		if (!dst[i])
			return (nc_dptr_free(dst), src = NULL, NULL);
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
	}
	dst[nc_dptr_size_y(src)] = NULL;
	return (dst);
}
