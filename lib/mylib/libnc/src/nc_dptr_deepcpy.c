/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dptr_deepcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:27:11 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/11 14:05:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

/* Make a deepcpy of a dptr whose ptrs has a variable length (the whole structure
is not a rectangle)*/
char	**nc_dptr_deepcpy(char **src)
{
	char	**p;
	int		size_y;
	int		i;
	int		j;

	size_y = nc_dptr_size_y(src);
	if (!size_y)
		return (NULL);
	p = malloc (sizeof(char *) * (size_y + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = malloc (sizeof(char) * (ft_strlen(src[i])));
		if (!p[i])
			return (nc_dptr_free(p), src = NULL, NULL);
		j = 0;
		while (src[i][j])
		{
			p[i][j] = src[i][j];
			j++;
		}
		p[i][j] = '\0';
		i++;
	}
	p[size_y] = NULL;
	return (p);
}
