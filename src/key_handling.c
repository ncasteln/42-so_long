/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:15 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:41:59 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	win_control(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

static int	is_possible_move(t_state *game, int y, int x)
{
	int		next_py;
	int		next_px;
	char	cell;

	next_py = game->data->p.y + y;
	next_px = game->data->p.x + x;
	cell = game->data->map[next_py][next_px];
	if (cell == '0' || cell == 'C' || (cell == 'E' && game->data->c > 0))
		return (display_steps(game), 1);
	else if (cell == 'E' && game->data->c == 0)
		return (display_steps(game), 1);
	return (0);
}

static void	p_control(mlx_key_data_t keydata, t_state *game)
{
	if (keydata.key == MLX_KEY_W && is_possible_move(game, -1, 0))
		p_move(game, -1, 0);
	if (keydata.key == MLX_KEY_D && is_possible_move(game, 0, +1))
		p_move(game, 0, +1);
	if (keydata.key == MLX_KEY_S && is_possible_move(game, +1, 0))
		p_move(game, +1, 0);
	if (keydata.key == MLX_KEY_A && is_possible_move(game, 0, -1))
		p_move(game, 0, -1);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_state	*game;

	game = (t_state *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (!game->data->is_end)
			p_control(keydata, game);
		win_control(keydata, game);
	}
}
