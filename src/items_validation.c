/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:44:20 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:46:36 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Returns (1) if there is already the element, otherwise set its coordinates */
int	is_double_item(char c, t_data *data, int y, int x)
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
	return (0);
}

int	is_valid_item(char c)
{
	if (c == 'P' || c == '1' || c == 'E' || c == '0' || c == 'C')
		return (1);
	return (0);
}
