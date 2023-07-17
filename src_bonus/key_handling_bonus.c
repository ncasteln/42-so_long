/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:15 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 12:45:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	control_window(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key	== MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

static void	move_pc(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key	== MLX_KEY_W && is_possible_move(game, -1, 0, 'P'))
		move_char(game, -1, 0);
	if (keydata.key	== MLX_KEY_D && is_possible_move(game, 0, +1, 'P'))
		move_char(game, 0, +1);
	if (keydata.key	== MLX_KEY_S && is_possible_move(game, +1, 0, 'P'))
		move_char(game, +1, 0);
	if (keydata.key	== MLX_KEY_A && is_possible_move(game, 0, -1, 'P'))
		move_char(game, 0, -1);
	if (game->map[game->p.y][game->p.x] == 'E' && game->c == 0)
	{
		game->steps += 1;
		ft_printf("Steps: %d\n", game->steps);
		mlx_close_window(game->mlx);
	}
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_state	*game;

	game = (t_state *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		move_pc(keydata, game);
		control_window(keydata, game);
	}
}
