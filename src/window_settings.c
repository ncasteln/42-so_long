/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/11 14:17:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_state *game)
{
	int	width;
	int	height;
	int	size_x;
	int	size_y;

	size_x = nc_dptr_size_x(game->map);
	size_y = nc_dptr_size_y(game->map);
	if (size_x > 40 || size_y > 25) // ---------- -set new limit ?????
		nc_exit("Map too big", __FILE__, __func__, __LINE__);
	width = size_x * 64;
	height = size_y * 64;

	game->mlx = mlx_init(width, height, "so_long", true);
	if (!game->mlx)
		nc_exit("MLX could not init", __FILE__, __func__, __LINE__);
}
