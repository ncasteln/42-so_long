/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:14:44 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 12:51:52 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_counter(t_state *game)
{
	if (game->counter == 101)
		game->counter = 0;
	game->counter++;
}

void	handle_event(void *param)
{
	t_state		*game;

	game = (t_state *) param;
	set_counter(game);
	if (game->counter % 25 == 0 && game->counter < 50)
		move_npc(game);
}
