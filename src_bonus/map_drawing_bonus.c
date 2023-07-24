/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 16:29:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (game->data->map[y][x] == 'N' && c == 'N')
		mlx_image_to_window(game->mlx, game->img->n, x * 64, y * 64);
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
	int		y;
	int		x;
	t_state	*game;

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
	mlx_image_to_window(game->mlx, game->img->steps_img, 24, 24);
}
