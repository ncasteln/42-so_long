/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_elements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:17 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/25 09:07:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_window(t_state *game)
{
	int32_t	width;
	int32_t	height;
	int		size_x;
	int		size_y;

	size_x = dptr_size(game->data->map, 'x');
	size_y = dptr_size(game->data->map, 'y');
	width = size_x * 64;
	height = size_y * 64;
	if (width > WIDTH_LIMIT || height > HEIGHT_LIMIT)
		return (free_state(game), err_print(MLX_WINFAIL));
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (free_state(game), err_print(MLX_FAIL));
}

int	init_textures(t_state *game)
{
	game->txt = malloc (sizeof(mlx_texture_t) * 10);
	if (!game->txt)
		return (0);
	game->txt->p_r = mlx_load_png("./textures/player_r.png");
	game->txt->p_l = mlx_load_png("./textures/player_l.png");
	game->txt->pe_r = mlx_load_png("./textures/pe_r.png");
	game->txt->pe_l = mlx_load_png("./textures/pe_l.png");
	game->txt->e_0 = mlx_load_png("./textures/exit_0.png");
	game->txt->e_1 = mlx_load_png("./textures/exit_1.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");
	game->txt->n = mlx_load_png("./textures/npc.png");
	return (1);
}

/* Init all the images. N of elements is 8 because 1 for every image and
1 in addition for the end_img (string "Game Over") */
int	init_img(t_state *game)
{
	if (!init_textures(game))
		return (0);
	game->img = malloc (sizeof(t_img) * 8);
	if (!game->img)
		return (0);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p_r);
	game->img->e = mlx_texture_to_image(game->mlx, game->txt->e_0);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	game->img->ground = mlx_texture_to_image(game->mlx, game->txt->ground);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->n = mlx_texture_to_image(game->mlx, game->txt->n);
	game->img->steps_img = mlx_put_string(game->mlx, "Steps: 0", 0, 0);
	return (1);
}
