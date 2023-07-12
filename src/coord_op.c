/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:47:18 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/10 16:24:58 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coord_print(t_coord *coord) // ------------ export function
{
	while (coord && coord->next)
	{
		ft_printf("[%d][%d]\n", coord->y, coord->x);
		coord = coord->next;
	}
	ft_printf("[%d][%d]\n", coord->y, coord->x);
}

static void	coord_pop(t_coord **coord)
{
	t_coord	*temp;

	(*coord)->y = 0;
	(*coord)->x = 0;
	temp = *coord;
	*coord = (*coord)->next;
	free(temp);
}

void	coord_match(t_coord **coord, int y, int x)
{
	if ((*coord)->y == y && (*coord)->x == x)
		coord_pop(coord);
	// else if (coord_last(*coord)->y == y && coord_last(*coord)->x == x)
	// {
	// 	// remove_last
	// }
	// else

}

void	coord_clear(t_coord **coord)
{
	t_coord	*temp;

	while (*coord)
	{
		temp = (*coord)->next;
		(*coord)->x = 0;
		(*coord)->y = 0;
		free(*coord);
		*coord = temp;
	}
}

t_coord	*coord_new(int y, int x)
{
	t_coord	*new;

	new = malloc (sizeof(t_coord));
	if (!new)
		return (NULL);
	new->y = y;
	new->x = x;
	new->next = NULL;
	return (new);
}

int	coord_size(t_coord *coord)
{
	int	len;

	len = 0;
	while (coord && coord->next)
	{
		len++;
		coord = coord->next;
	}
	len++;
	return (len);
}

static t_coord	*coord_last(t_coord *coord)
{
	while (coord && coord->next)
		coord = coord->next;
	return (coord);
}

void	coord_append(t_coord **coord, t_coord *new_node)
{
	if ((*coord))
		coord_last(*coord)->next = new_node;
	else
		(*coord) = new_node;
}
