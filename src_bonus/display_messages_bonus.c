/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 12:24:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->msg->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x * 64, mid_y * 64); // make central
}

void	display_steps(t_state *game)
{
	game->steps += 1;
	if (game->msg->steps)
		free(game->msg->steps);
	game->msg->steps = ft_strjoin("Steps: ", ft_itoa(game->steps)); // need to save the pointer
	redraw_items(game, 'S');
}
