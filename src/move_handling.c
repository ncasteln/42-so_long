/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 15:42:43 by ncasteln         ###   ########.fr       */
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

void	update_map(t_state *game, int next_p_y, int next_p_x)
{
	game->map[game->p.y][game->p.x] = '0';
	game->p.y = next_p_y;
	game->p.x = next_p_x;
	game->map[next_p_y][next_p_x] = 'P';
}

/* The function accept the inverement value of each coordinate */
void	move_player(t_state *game, int y, int x)
{
	int	next_p_x;
	int	next_p_y;

	next_p_x = game->p.x + x;
	next_p_y = game->p.y + y;
	if (game->map[next_p_y][next_p_x] == 'C')
	{
		game->c -= 1;
		update_map(game, next_p_y, next_p_x);
		redraw_collectibles(game);
	}
	else if (game->map[next_p_y][next_p_x] == '0')
		update_map(game, next_p_y, next_p_x);
}

void	handle_move(t_state *game, int y, int x)
{
	move_player(game, y, x);
	mlx_delete_image(game->mlx, game->img->p);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
}

int	is_possible_move(t_state *game, int y, int x)
{
	int	next_p_y;
	int	next_p_x;
	int	cell;

	game->steps += 1;
	ft_printf("Steps: %d\n", game->steps);
	next_p_y = game->p.y + y;
	next_p_x = game->p.x + x;
	cell = game->map[next_p_y][next_p_x];
	if (cell == '0' || cell == 'C' || cell == '!')
		return (1);
	if (cell == 'E' && game->c == 0)
	{
		mlx_close_window(game->mlx);
		return (0);
	}
	return (0);
}

