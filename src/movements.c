/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 15:25:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	redraw_collectibles(t_state *game)
{
	int	y;
	int	x;

	mlx_delete_image(game->mlx, game->img->c);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);

	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	move_it(t_state *game, int y, int x) // y and x are the n of moves in that direction
{
	int	next_x;
	int	next_y;

	next_x = game->p.x + x;
	next_y = game->p.y + y;
	if (game->map[next_y][next_x] == 'C')
	{
		game->map[game->p.y][game->p.x] = '0';
		game->p.y = next_y;
		game->p.x = next_x;
		game->map[game->p.y][game->p.x] = 'P';
		game->c -= 1;
		redraw_collectibles(game);
	}
	else
	{
		game->map[game->p.y][game->p.x] = '0';
		game->p.y = next_y;
		game->p.x = next_x;
		game->map[game->p.y][game->p.x] = 'P';
	}
}

int	is_possible_move(t_state *game, int y, int x)
{
	int	py;
	int	px;
	int	cell;

	py = game->p.y;
	px = game->p.x;
	cell = game->map[py + y][px + x];
	if (cell == '0' || cell == 'C')
	{
		// game->img->c->instances[0].enabled = false;
		return (1);
	}
	if (cell == 'E' && game->c == 0)
	{
		exit (1);  // -------------------------- game finished !!
		return (1);
	}
	return (0);
}
