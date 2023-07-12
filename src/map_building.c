/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 16:45:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_textures(t_state *game)
{
	game->txt = malloc (sizeof(mlx_texture_t) * 5); // protect
	if (!game->txt)
		nc_exit("Failed to get textures", __FILE__, __func__, __LINE__);
	game->txt->p = mlx_load_png("./textures/player_0.png");
	game->txt->e = mlx_load_png("./textures/exit.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");
	game->txt->enemy = mlx_load_png("./textures/enemy.png");
}

static void	init_img(t_state *game)
{
	init_textures(game);
	game->img = malloc (sizeof(t_img) * 5); // protect
	if (!game->img) // free(txtures)
		nc_exit("Failed to get images", __FILE__, __func__, __LINE__);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	game->img->e = mlx_texture_to_image(game->mlx, game->txt->e);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	game->img->ground = mlx_texture_to_image(game->mlx, game->txt->ground);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->enemy = mlx_texture_to_image(game->mlx, game->txt->enemy);
}

void	init_map(void *param)
{
	int			y;
	int			x;
	t_state 	*game;

	game = (t_state *) param;
	init_img(game);
	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			mlx_image_to_window(game->mlx, game->img->ground, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
			if (game->map[y][x] == '!')
				mlx_image_to_window(game->mlx, game->img->enemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
