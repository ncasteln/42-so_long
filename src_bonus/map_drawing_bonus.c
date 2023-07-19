/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 16:58:49 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	init_textures(t_state *game)
{
	game->txt = malloc (sizeof(mlx_texture_t) * 11);
	if (!game->txt)
		return (0);
	game->txt->p_r = mlx_load_png("./textures/player_r.png");
	game->txt->p_l = mlx_load_png("./textures/player_l.png");
	game->txt->pe_r = mlx_load_png("./textures/player_exit_r.png");
	game->txt->pe_l = mlx_load_png("./textures/player_exit_l.png");
	game->txt->e_0 = mlx_load_png("./textures/exit_0.png");
	game->txt->e_1 = mlx_load_png("./textures/exit_1.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");
	game->txt->n = mlx_load_png("./textures/npc.png");
	game->txt->ne = mlx_load_png("./textures/npc_e.png");
	return (1);
}

static int	init_img(t_state *game)
{
	if (!init_textures(game))
		return (0);
	game->img = malloc (sizeof(t_img) * 8); // n of total images + 1 for end
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

static void	reset_p_image(t_state *game)
{
	mlx_delete_image(game->mlx, game->img->p);
	if (!game->is_end)
	{
		if (game->p_last == 'r' || !game->p_last)
		{
			if (game->is_exit == 1)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->pe_r);
			else // if (game->is_exit == 0)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->p_r);
		}
		else if (game->p_last == 'l')
		{
			if (game->is_exit == 1)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->pe_l);
			else // if (game->is_exit == 0)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->p_l);
		}
	}
	else
		game->img->p = mlx_texture_to_image(game->mlx, game->txt->e_1);
}

static void	reset_image(t_state *game, char c)
{
	if (c == 'C')
	{
		mlx_delete_image(game->mlx, game->img->c);
		game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	}
	else if (c == 'P')
		reset_p_image(game);
	else if (c == 'N')
	{
		mlx_delete_image(game->mlx, game->img->n);
		if (game->is_exit == 2 && !(game->is_end))
			game->img->n = mlx_texture_to_image(game->mlx, game->txt->ne);
		else if (game->is_exit == 1 && game->is_end)
			game->img->n = mlx_texture_to_image(game->mlx, game->txt->ne);
		else
			game->img->n = mlx_texture_to_image(game->mlx, game->txt->n);
	}
	else if (c == 'S')
	{
		mlx_delete_image(game->mlx, game->img->steps_img);
		game->img->steps_img = mlx_put_string(game->mlx, game->steps_str, 16, 16);
	}
	else if (c == 'E')
	{
		mlx_delete_image(game->mlx, game->img->e);
		game->img->e = mlx_texture_to_image(game->mlx, game->txt->e_1);
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
			else if (game->map[y][x] == 'N')
				mlx_image_to_window(game->mlx, game->img->n, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
			x++;
		}
		y++;
	}
	if (game->is_end)
		display_end(game);
}

static void	images_to_window(t_state *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
	else if (game->map[y][x] == 'N')
		mlx_image_to_window(game->mlx, game->img->n, x * 64, y * 64);
}

int	draw_map(void *param)
{
	int		y;
	int		x;
	t_state	*game;

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
			mlx_image_to_window(game->mlx, game->img->steps_img, 16, 16); // protect from -1 ??? ---- remove ???
			x++;
		}
		y++;
	}
	return (1);
}
