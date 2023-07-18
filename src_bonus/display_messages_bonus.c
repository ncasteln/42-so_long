/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 12:48:59 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->img->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	char	*temp_1;
	char	*temp_2;

	game->steps += 1;
	if (game->steps_str)
		free(game->steps_str);
	temp_1 = ft_strdup("Steps: ");
	temp_2 = ft_itoa(game->steps);
	game->steps_str = ft_strjoin(temp_1, temp_2);
	free(temp_1);
	free(temp_2);
	redraw_items(game, 'S');
}
