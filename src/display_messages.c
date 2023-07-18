/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:07:27 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 14:00:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err_print(int err)
{
	ft_putendl_fd("Error", 2);
	if (err == 1)
		ft_putendl_fd("Invalid map", 2);
	if (err == 2)
		ft_putendl_fd("MLX failed", 2);
	if (err == 3)
		ft_putendl_fd("Map building failed", 2);
	return (err);
}

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	game->steps += 1;
	ft_printf("Steps: %d\n", game->steps);
}
