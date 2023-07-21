/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:21:52 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 14:51:25 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function make two things: counts the C and E elements, and returns
when it finds a wall, the player position, an already found position or
an enemy. In these cases returns (0) as false, and the tile is not overwrit*/
static int	count_item(char item, int *c, int *e)
{
	if (item == 'P' || item == '1' || item == ' ')
		return (0);
	if (item == 'C')
		*c -= 1;
	if (item == 'E')
		*e -= 1;
	return (1);
}

static void	check_neighbors(char **map, int y, int x, int *items)
{
	int	d_limit;
	int	r_limit;

	d_limit = nc_dptr_size_y(map) - 1;
	r_limit = nc_dptr_size_x(map) - 1;
	if ((y - 1 > 0) && count_item(map[y - 1][x], &items[0], &items[1]))
	{
		map[y - 1][x] = ' ';
		check_neighbors(map, y - 1, x, items);
	}
	if (x + 1 < r_limit && count_item(map[y][x + 1], &items[0], &items[1]))
	{
		map[y][x + 1] = ' ';
		check_neighbors(map, y, x + 1, items);
	}
	if (y + 1 < d_limit && count_item(map[y + 1][x], &items[0], &items[1]))
	{
		map[y + 1][x] = ' ';
		check_neighbors(map, y + 1, x, items);
	}
	if (x - 1 > 0 && count_item(map[y][x - 1], &items[0], &items[1]))
	{
		map[y][x - 1] = ' ';
		check_neighbors(map, y, x - 1, items);
	}
}

void	is_valid_path(t_data *data)
{
	int		items[2];
	char	**map_cpy;

	items[0] = data->c;
	items[1] = data->e;
	map_cpy = nc_dptr_deepcpy(data->map);
	if (!map_cpy)
		return (free_data(data), err_print(MAP_FAIL));
	check_neighbors(map_cpy, data->p.y, data->p.x, items);
	if (items[0] != 0 || items[1] != 0)
		return (free_data(data), nc_dptr_free(map_cpy), err_print(INV_PATH));
	return (nc_dptr_free(map_cpy));
}
