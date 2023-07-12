/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ptr_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:15:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/10 13:48:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**lst_to_double_ptr(t_list *lst, int y)
{
	char	**map;
	int		i;

	map = ft_calloc ((y + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		map[i] = ft_calloc (ft_strlen(lst->content), sizeof(char));
		if (!map[i])
			return (NULL); // free(everything)
		ft_strlcpy(map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
