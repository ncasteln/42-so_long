/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 10:49:18 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_state *game)
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
		return (err_print(game, INV_MAPSIZE));
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (err_print(game, MLX_FAIL));
}
