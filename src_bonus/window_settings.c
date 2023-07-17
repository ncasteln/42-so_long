/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 09:46:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_state *game)
{
	int	width;
	int	height;
	int	size_x;
	int	size_y;

	size_x = nc_dptr_size_x(game->map);
	size_y = nc_dptr_size_y(game->map);
	if (size_x > 40 || size_y > 25) // ------------------------------------  set new limit ?????
		return (0);
	width = size_x * 64;
	height = size_y * 64;
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (0);
	return (1);
}
