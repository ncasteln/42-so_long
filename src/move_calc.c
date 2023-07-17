/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 09:29:19 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Set the current position of player to '0', calculates its new position
and set the map cell to its char - like a swap */
static void	swap_position(t_state *game, int next_py, int next_px, char c)
{
	game->map[game->p.y][game->p.x] = c;
	game->p.y = next_py;
	game->p.x = next_px;
	game->map[next_py][next_px] = 'P';
}

static void	reset_exit(t_state *game, int next_py, int next_px)
{
	game->is_exit = 0;
	swap_position(game, next_py, next_px, 'E');
}

/* The function accept the inverement value of each coordinate */
void	move_player(t_state *game, int y, int x)
{
	int	next_px;
	int	next_py;

	next_px = game->p.x + x;
	next_py = game->p.y + y;
	if (game->map[next_py][next_px] == 'E')
	{
		game->is_exit = 1;
		swap_position(game, next_py, next_px, 'E');
	}
	else if (game->map[next_py][next_px] == 'C')
	{
		if (game->is_exit == 1)
			reset_exit(game, next_py, next_px);
		game->c -= 1;
		swap_position(game, next_py, next_px, '0');
		redraw_items(game, 'C');
	}
	else if (game->map[next_py][next_px] == '0')
	{
		if (game->is_exit == 1)
			reset_exit(game, next_py, next_px);
		else
			swap_position(game, next_py, next_px, '0');
	}
	redraw_items(game, 'P');
}

int	is_possible_move(t_state *game, int y, int x)
{
	int	next_py;
	int	next_px;
	int	cell;

	next_py = game->p.y + y;
	next_px = game->p.x + x;
	cell = game->map[next_py][next_px];
	if (cell == '0' || cell == 'C' || (cell == 'E' && game->c > 0))
	{
		game->steps += 1;
		ft_printf("Steps: %d\n", game->steps);
		return (1);
	}
	if (cell == 'E' && game->c == 0)
	{
		game->steps += 1;
		ft_printf("Steps: %d\n", game->steps);
		mlx_close_window(game->mlx);
		return (0);
	}
	return (0);
}

