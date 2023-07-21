/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move_calc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:43 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 13:28:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	swap_position_n(t_state *game, int next_y, int next_x, char c)
{
	if (c == 'E')
		game->data->is_exit = 0;
	game->data->map[game->data->n.y][game->data->n.x] = c;
	game->data->n.y = next_y;
	game->data->n.x = next_x;
	game->data->map[next_y][next_x] = 'N';
}

static void	find_move(t_state *game, t_char *next_n)
{
	int	rn;

	rn = rand() % 4;
	if (rn == 0)
		next_n->y = -1;
	if (rn == 1)
		next_n->x = 1;
	if (rn == 2)
		next_n->y = 1;
	if (rn == 3)
		next_n->x = -1;
	while (!is_possible_move(game, next_n->y, next_n->x, 'N'))
	{
		next_n->y = 0;
		next_n->x = 0;
		rn = rand() % 4;
		if (rn == 0)
			next_n->y = -1;
		if (rn == 1)
			next_n->x = 1;
		if (rn == 2)
			next_n->y = 1;
		if (rn == 3)
			next_n->x = -1;
	}
}

static int	a_move_is_available(char c)
{
	if (c == '0' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

static int	is_blocked(t_data *data)
{
	if (a_move_is_available(data->map[data->n.y - 1][data->n.x]))
		return (0);
	if (a_move_is_available(data->map[data->n.y][data->n.x + 1]))
		return (0);
	if (a_move_is_available(data->map[data->n.y + 1][data->n.x]))
		return (0);
	if (a_move_is_available(data->map[data->n.y][data->n.x - 1]))
		return (0);
	return (1);
}

void	n_move(t_state *game)
{
	t_char	next_n;
	int		ny;
	int		nx;

	ny = game->data->n.y;
	nx = game->data->n.x;
	next_n.y = 0;
	next_n.x = 0;
	if (!is_blocked(game->data))
	{
		find_move(game, &next_n);
		if (game->data->map[ny + next_n.y][nx + next_n.x] == 'E')
		{
			game->data->is_exit = 2;
			swap_position_n(game, ny + next_n.y, nx + next_n.x, '0');
		}
		else
		{
			if (game->data->is_exit == 2)
				swap_position_n(game, ny + next_n.y, nx + next_n.x, 'E');
			else
				swap_position_n(game, ny + next_n.y, nx + next_n.x, '0');
		}
		redraw_items(game, 'N');
	}
}
