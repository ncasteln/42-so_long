/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_dptr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:15:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 14:56:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			return (nc_dptr_free(map), NULL);
		ft_strlcpy(map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
