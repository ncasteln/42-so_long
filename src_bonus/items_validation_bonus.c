/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_validation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:11:00 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 12:16:12 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Returns (1) if there is already the element, otherwise set its coordinates */
int	is_duplicate_item(char c, t_data *data, int y, int x)
{
	if (c == 'P')
	{
		if (data->p.x || data->p.y)
			return (1);
		data->p.y = y;
		data->p.x = x;
	}
	if (c == 'E')
	{
		if (data->e)
			return (1);
		data->e += 1;
	}
	if (c == 'N')
	{
		if (data->n.x || data->n.y)
			return (1);
		data->n.y = y;
		data->n.x = x;
	}
	return (0);
}

int	is_valid_item(char c)
{
	if (c == 'P' || c == '1' || c == 'E' || c == '0' || c == 'C' || c == 'N')
		return (1);
	return (0);
}
