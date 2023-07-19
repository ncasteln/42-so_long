/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 09:46:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_textures(t_state *game)
{
	game->txt = malloc (sizeof(mlx_texture_t) * 5);
	if (!game->txt)
		return (0);
	game->txt->p = mlx_load_png("./textures/player_r.png");
	game->txt->e = mlx_load_png("./textures/exit.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");
	return (1);
}

static int	init_img(t_state *game)
{
	if (!init_textures(game))
		return (0);
	game->img = malloc (sizeof(t_img) * 5);
	if (!game->img)
		return (0);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	game->img->e = mlx_texture_to_image(game->mlx, game->txt->e);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	game->img->ground = mlx_texture_to_image(game->mlx, game->txt->ground);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	return (1);
}

void	reset_image(t_state *game, char c)
{
	if (c == 'C')
	{
		mlx_delete_image(game->mlx, game->img->c);
		game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	}
	else if (c == 'P')
	{
		mlx_delete_image(game->mlx, game->img->p);
		game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	}
}

void	redraw_items(t_state *game, char c)
{
	int	y;
	int	x;

	reset_image(game, c);
	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void	images_to_window(t_state *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
	if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
	if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
}

int	draw_map(void *param)
{
	int			y;
	int			x;
	t_state 	*game;

	game = (t_state *) param;
	if (!init_img(game))
		return (err_print(game, 10), 10);
	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			mlx_image_to_window(game->mlx, game->img->ground, x * 64, y * 64); // protect from -1 ???
			images_to_window(game, y, x);
			x++;
		}
		y++;
	}
	return (1);
}
