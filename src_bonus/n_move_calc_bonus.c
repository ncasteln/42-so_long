/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move_calc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:43 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/25 09:03:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	swap_position_n(t_state *game, int next_y, int next_x, char c)
{
	game->data->map[game->data->n.y][game->data->n.x] = c;
	game->data->n.y = next_y;
	game->data->n.x = next_x;
	game->data->map[next_y][next_x] = 'N';
}

static void	find_move(t_char *next_n)
{
	int	rn;

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

static void	n_move(t_state *game, int next_y, int next_x)
{
	int	ny;
	int	nx;

	ny = game->data->n.y;
	nx = game->data->n.x;
	swap_position_n(game, ny + next_y, nx + next_x, '0');
}

void	n_handler(t_state *game)
{
	t_char	next_n;
	int		rn;

	rn = rand() % 4;
	if (rn == 0)
		next_n.y = -1;
	if (rn == 1)
		next_n.x = 1;
	if (rn == 2)
		next_n.y = 1;
	if (rn == 3)
		next_n.x = -1;
	next_n.x = 0;
	next_n.y = 0;
	if (!game->data->is_end && game->data->n.x && game->data->n.y)
	{
		if (!is_blocked(game->data))
		{
			while (!is_possible_move(game, next_n.y, next_n.x, 'N'))
				find_move(&next_n);
			n_move(game, next_n.y, next_n.x);
			redraw_items(game, 'N');
		}
	}
}
