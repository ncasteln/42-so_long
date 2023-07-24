/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 16:34:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (game->data->is_end)
			game->img->p = mlx_texture_to_image(game->mlx, game->txt->e_1);
		else
		{
			if (game->data->is_exit)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->pe_r);
			else
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
		}
	}
	else if (c == 'E')
	{
		mlx_delete_image(game->mlx, game->img->e);
		game->img->e = mlx_texture_to_image(game->mlx, game->txt->e_1);
	}
}

static void	images_to_window(t_state *game, int y, int x, char c)
{
	if (game->data->map[y][x] == '1' && c == '1')
		mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
	else if (game->data->map[y][x] == 'C' && c == 'C')
		mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
	else if (game->data->map[y][x] == 'E' && c == 'E')
		mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
	else if (game->data->map[y][x] == 'P' && c == 'P')
		mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
}

void	redraw_items(t_state *game, char c)
{
	int	y;
	int	x;

	reset_image(game, c);
	y = 0;
	while (y < dptr_size(game->data->map, 'y'))
	{
		x = 0;
		while (x < dptr_size(game->data->map, 'x'))
		{
			images_to_window(game, y, x, c);
			x++;
		}
		y++;
	}
	if (game->data->is_end)
		display_end(game);
}

void	draw_map(void *param)
{
	int			y;
	int			x;
	t_state		*game;

	game = (t_state *) param;
	if (!init_img(game))
		return (free_state(game), err_print(MLX_IMG_FAIL));
	y = 0;
	while (y < dptr_size(game->data->map, 'y'))
	{
		x = 0;
		while (x < dptr_size(game->data->map, 'x'))
		{
			mlx_image_to_window(game->mlx, game->img->ground, x * 64, y * 64);
			images_to_window(game, y, x, game->data->map[y][x]);
			x++;
		}
		y++;
	}
}
