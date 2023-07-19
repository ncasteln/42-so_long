/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_move_calc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:43 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:53 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	swap_position(t_state *game, int next_y, int next_x)
{
	game->map[game->n.y][game->n.x] = '0';
	game->n.y = next_y;
	game->n.x = next_x;
	game->map[next_y][next_x] = 'N';
}

static int	a_move_is_available(char c)
{
	if (c == '0' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	is_blocked(t_state *game)
{
	if (a_move_is_available(game->map[game->n.y - 1][game->n.x]))
		return (0);
	if (a_move_is_available(game->map[game->n.y][game->n.x + 1]))
		return (0);
	if (a_move_is_available(game->map[game->n.y + 1][game->n.x]))
		return (0);
	if (a_move_is_available(game->map[game->n.y][game->n.x - 1]))
		return (0);
	return (1);
}

void	npc_move(t_state *game)
{
	t_char	next_n;
	int		ny;
	int		nx;

	ny = game->n.y;
	nx = game->n.x;
	next_n.y = 0;
	next_n.x = 0;
	if (!is_blocked(game))
	{
		find_move(game, &next_n);
		if (game->map[ny + next_n.y][nx + next_n.x] == 'E')
		{
			game->is_exit = 2;
			swap_position(game, ny + next_n.y, nx + next_n.x);
			ft_printf("Over the exit !");
		}
		else
		{
			if (game->is_exit == 2)
			{
				game->is_exit = 0;
				game->map[ny][nx] = 'E';
				game->n.y += next_n.y;
				game->n.x += next_n.x;
				game->map[game->n.y][game->n.x] = 'N';
			}
			else
				swap_position(game, ny + next_n.y, nx + next_n.x);
		}
		redraw_items(game, 'N');
	}
}
