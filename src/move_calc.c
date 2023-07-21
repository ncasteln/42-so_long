/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:43:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Swap position of the player depending of the piece of map where it goes */
static void	swap_position(t_state *game, int next_py, int next_px, char c)
{
	if (c == 'E')
		game->data->is_exit = 0;
	game->data->map[game->data->p.y][game->data->p.x] = c;
	game->data->p.y = next_py;
	game->data->p.x = next_px;
	game->data->map[next_py][next_px] = 'P';
}

/* Handles the move of pc to a colectible cell */
static void	pc_to_e(t_state *game, int next_py, int next_px)
{
	game->data->is_exit = 1;
	swap_position(game, next_py, next_px, '0');
	if (!game->data->c)
		game->data->is_end = 1;
}

static void	pc_to_c(t_state *game, int next_py, int next_px)
{
	if (game->data->is_exit == 1)
		swap_position(game, next_py, next_px, 'E');
	game->data->c -= 1;
	swap_position(game, next_py, next_px, '0');
	redraw_items(game, 'C');
	if (game->data->c == 0)
		redraw_items(game, 'E');
}

static void	pc_to_0(t_state *game, int next_py, int next_px)
{
	if (game->data->is_exit == 1)
		swap_position(game, next_py, next_px, 'E');
	else
		swap_position(game, next_py, next_px, '0');
}

/* The function handle the moves to new position of the player char
and accept the increment value of each coordinate */
void	p_move(t_state *game, int y, int x)
{
	int	next_px;
	int	next_py;

	next_px = game->data->p.x + x;
	next_py = game->data->p.y + y;
	if (game->data->map[next_py][next_px] == 'E')
		pc_to_e(game, next_py, next_px);
	else if (game->data->map[next_py][next_px] == 'C')
		pc_to_c(game, next_py, next_px);
	else if (game->data->map[next_py][next_px] == '0')
		pc_to_0(game, next_py, next_px);
	redraw_items(game, 'P');
}
