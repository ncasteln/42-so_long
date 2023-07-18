/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 14:52:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_state *game)
{
	int32_t	width;
	int32_t	height;
	int	size_x;
	int	size_y;

	size_x = nc_dptr_size_x(game->map);
	size_y = nc_dptr_size_y(game->map);
	width = size_x * 64;
	height = size_y * 64;
	if (width > WIDTH_LIMIT || height > HEIGHT_LIMIT)
		return (0);
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (0);
	return (1);
}
