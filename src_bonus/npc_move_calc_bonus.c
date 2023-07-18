/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_move_calc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:43 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 10:56:52 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	find_move(t_state *game, t_char *next_npc)
{
	int	rn;

	rn = rand() % 4;
	if (rn == 0)
		next_npc->y = -1;
	if (rn == 1)
		next_npc->x = 1;
	if (rn == 2)
		next_npc->y = 1;
	if (rn == 3)
		next_npc->x = -1;
	while (!is_possible_move(game, next_npc->y, next_npc->x, 'N'))
	{
		next_npc->y = 0;
		next_npc->x = 0;
		rn = rand() % 4;
		if (rn == 0)
			next_npc->y = -1;
		if (rn == 1)
			next_npc->x = 1;
		if (rn == 2)
			next_npc->y = 1;
		if (rn == 3)
			next_npc->x = -1;
	}
}


static void	swap_position(t_state *game, int next_y, int next_x)
{
	game->map[game->n.y][game->n.x] = '0';
	game->n.y = next_y;
	game->n.x = next_x;
	game->map[next_y][next_x] = 'N';
}

int	is_blocked(t_state *game)
{
	if (game->map[game->n.y - 1][game->n.x] == '0')
		return (0);
	if (game->map[game->n.y][game->n.x + 1] == '0')
		return (0);
	if (game->map[game->n.y + 1][game->n.x] == '0')
		return (0);
	if (game->map[game->n.y][game->n.x - 1] == '0')
		return (0);
	return (1);
}

void	npc_move(t_state *game)
{
	t_char next_npc;

	next_npc.y = 0;
	next_npc.x = 0;
	if (!is_blocked(game))
	{
		find_move(game, &next_npc);
		swap_position(game, game->n.y + next_npc.y, game->n.x + next_npc.x);
		redraw_items(game, 'N');
	}
}
