/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dptr_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:27:11 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 09:19:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Convert a lst whose content is a char *s to a dptr who points to each str */
char	**lst_to_dptr(t_list *lst, int y)
{
	char	**map;
	int		i;

	map = malloc (sizeof(char *) * (y + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		map[i] = malloc (sizeof(char) * ft_strlen(lst->content));
		if (!map[i])
			return (dptr_free(map), NULL);
		ft_strlcpy(map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	dptr_free(char **p)
{
	int	i;

	i = 0;
	if (p[i])
	{
		while (p[i])
		{
			free(p[i]);
			i++;
		}
		free(p);
	}
}

/* Returns the size of the specified axis. In case of 'y' is returned the
n of allocated pointers, aka a line. In case of 'x' the size of a single line
is returned, assuming that the shape is rectangular. If it's not rectangulare
returns (-1) */
int	dptr_size(char **s, char axis)
{
	int	i;
	int	j;
	int	size_x;

	i = 0;
	if (axis == 'y')
	{
		while (s[i])
			i++;
		return (i);
	}
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

static char	**dptr_allocate(int y)
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
char	**dptr_deepcpy(char **src)
{
	char	**dst;
	int		i;
	int		j;

	dst = dptr_allocate(dptr_size(src, 'y'));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = malloc (sizeof(char) * (ft_strlen(src[i]) + 1));
		if (!dst[i])
			return (dptr_free(dst), src = NULL, NULL);
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
	}
	dst[dptr_size(src, 'y')] = NULL;
	return (dst);
}
