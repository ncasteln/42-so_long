/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:15 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 17:31:59 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	control_window(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key	== MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			// free stuff
			ft_printf("[esc]");
		}
	}
	(void) game;
}

static void	move_character(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key	== MLX_KEY_W && is_possible_move(game, -1, 0)) // ---- UP
		handle_move(game, -1, 0);
	if (keydata.key	== MLX_KEY_D && is_possible_move(game, 0, +1)) // ---- RIGHT
		handle_move(game, 0, +1);
	if (keydata.key	== MLX_KEY_S && is_possible_move(game, +1, 0)) // ---- DOWN
		handle_move(game, +1, 0);
	if (keydata.key	== MLX_KEY_A && is_possible_move(game, 0, -1)) // ---- LEFT
		handle_move(game, 0, -1);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_state	*game;

	game = (t_state *) param;
	if (keydata.action == MLX_PRESS)
	{
		move_character(keydata, game);// - - - - remove every other key possibility
		control_window(keydata, game);
	}
	state_print(game);
}
