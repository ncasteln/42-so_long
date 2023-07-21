/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:14:44 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 13:11:36 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_counter(t_state *game)
{
	if (game->data->counter == 101)
		game->data->counter = 0;
	game->data->counter++;
}

void	handle_event(void *param)
{
	t_state		*game;

	game = (t_state *) param;
	set_counter(game);
	if (!game->data->is_end)
	{
		if (game->data->counter % 33 == 0)
			n_move(game);
	}
}
