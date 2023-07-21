/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:34:18 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 16:44:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_state *game)
{
	int32_t	width;
	int32_t	height;
	int		size_x;
	int		size_y;

	size_x = nc_dptr_size_x(game->data->map);
	size_y = nc_dptr_size_y(game->data->map);
	width = size_x * 64;
	height = size_y * 64;
	if (width > WIDTH_LIMIT || height > HEIGHT_LIMIT)
		return (free_state(game), err_print(INV_MAPSIZE));
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (free_state(game), err_print(MLX_FAIL));
}

int	init_textures(t_state *game)
{
	game->txt = malloc (sizeof(mlx_texture_t) * 7);
	if (!game->txt)
		return (0);
	game->txt->p = mlx_load_png("./textures/player_r.png");
	game->txt->e_0 = mlx_load_png("./textures/exit_0.png");
	game->txt->e_1 = mlx_load_png("./textures/exit_1.png");
	game->txt->pe_r = mlx_load_png("./textures/player_exit_r.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");
	return (1);
}

int	init_img(t_state *game)
{
	if (!init_textures(game))
		return (0);
	game->img = malloc (sizeof(t_img) * 5);
	if (!game->img)
		return (0);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	game->img->e = mlx_texture_to_image(game->mlx, game->txt->e_0);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	game->img->ground = mlx_texture_to_image(game->mlx, game->txt->ground);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	return (1);
}
