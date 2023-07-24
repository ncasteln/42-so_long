/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_move_calc_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:09:38 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 16:25:12 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Verify if player can move in that direction */
static int	p_can_move(t_state *game, int y, int x)
{
	int		next_py;
	int		next_px;
	char	cell;

	next_py = game->data->p.y + y;
	next_px = game->data->p.x + x;
	cell = game->data->map[next_py][next_px];
	if (cell == '0' || cell == 'C' || (cell == 'E' && game->data->c > 0))
		return (1);
	else if (cell == 'N')
	{
		game->data->is_end = 2;
		game->data->map[game->data->p.y][game->data->p.x] = '0';
		return (1);
	}
	else if ((cell == 'E' && game->data->c == 0))
		return (1);
	return (0);
}

static int	move_is_available(t_data *data, char c)
{
	if (c == '0' || (c == 'P' && !data->is_exit))
		return (1);
	return (0);
}

/* Verify if the is at least one move to perform. Different from
is_possible_move() which verifies the move to a defined direction */
int	is_blocked(t_data *data)
{
	if (move_is_available(data, data->map[data->n.y - 1][data->n.x]))
		return (0);
	if (move_is_available(data, data->map[data->n.y][data->n.x + 1]))
		return (0);
	if (move_is_available(data, data->map[data->n.y + 1][data->n.x]))
		return (0);
	if (move_is_available(data, data->map[data->n.y][data->n.x - 1]))
		return (0);
	return (1);
}

static int	n_can_move(t_state *game, int y, int x)
{
	int		next_ny;
	int		next_nx;
	char	cell;

	next_ny = game->data->n.y + y;
	next_nx = game->data->n.x + x;
	cell = game->data->map[next_ny][next_nx];
	if (cell == '0')
		return (1);
	if (cell == 'P')
	{
		game->data->is_end = 2;
		return (1);
	}
	return (0);
}

int	is_possible_move(t_state *game, int y, int x, char c)
{
	if (c == 'P')
		return (p_can_move(game, y, x));
	else if (c == 'N')
		return (n_can_move(game, y, x));
	return (0);
}
