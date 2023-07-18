/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 11:31:45 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Set the current position of player to '0', calculates its new position
and set the map cell to its char - like a swap */
static void	swap_position(t_state *game, int next_py, int next_px)
{
	game->map[game->p.y][game->p.x] = '0';
	game->p.y = next_py;
	game->p.x = next_px;
	game->map[next_py][next_px] = 'P';
}

/* Assumes that the player is covering the exit cell, so the exit has to be
redrawn in its original position */
static void	reset_exit(t_state *game, int next_py, int next_px)
{
	game->is_exit = 0;
	game->map[game->p.y][game->p.x] = 'E';
	game->p.y = next_py;
	game->p.x = next_px;
	game->map[next_py][next_px] = 'P';
}

/* Handles the move of pc to a colectible cell */
static void pc_to_e(t_state *game, int next_py, int next_px)
{
	game->is_exit = 1;
	swap_position(game, next_py, next_px);
	if (game->is_end)
		display_end(game);
}

static void pc_to_c(t_state *game, int next_py, int next_px)
{
	if (game->is_exit == 1)
		reset_exit(game, next_py, next_px);
	game->c -= 1;
	swap_position(game, next_py, next_px);
	redraw_items(game, 'C');
}

static void pc_to_0(t_state *game, int next_py, int next_px)
{
	if (game->is_exit == 1)
		reset_exit(game, next_py, next_px);
	else
		swap_position(game, next_py, next_px);
}

/* The function handle the moves to new position of the player char
and accept the increment value of each coordinate */
void	pc_move(t_state *game, int y, int x)
{
	int	next_px;
	int	next_py;

	next_px = game->p.x + x;
	next_py = game->p.y + y;
	if (game->map[next_py][next_px] == 'E')
		pc_to_e(game, next_py, next_px);
	else if (game->map[next_py][next_px] == 'C')
		pc_to_c(game, next_py, next_px);
	else if (game->map[next_py][next_px] == '0')
		pc_to_0(game, next_py, next_px);
	redraw_items(game, 'P');
}

int	is_possible_move(t_state *game, int y, int x)
{
	int	next_py;
	int	next_px;
	char cell;

	next_py = game->p.y + y;
	next_px = game->p.x + x;
	cell = game->map[next_py][next_px];
	if (cell == '0' || cell == 'C' || (cell == 'E' && game->c > 0))
		return (display_steps(game), 1);
	else if (cell == 'E' && game->c == 0)
	{
		game->is_end = 1;
		return (display_steps(game), 1);
	}
	return (0);
}

