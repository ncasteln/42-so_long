/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:15 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 14:24:00 by ncasteln         ###   ########.fr       */
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
	if (keydata.action == MLX_PRESS)
	{

		if (keydata.key	== MLX_KEY_W && is_possible_move(game, -1, 0)) // -------------- UP
		{
			move_it(game, -1, 0);
			mlx_delete_image(game->mlx, game->img->p);
			game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
			mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
		}
		if (keydata.key	== MLX_KEY_D && is_possible_move(game, 0, +1)) // -------------- RIGHT
		{
			move_it(game, 0, +1);
			mlx_delete_image(game->mlx, game->img->p);
			game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
			mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
		}
		if (keydata.key	== MLX_KEY_S && is_possible_move(game, +1, 0)) // -------------- DOWN
		{
			move_it(game, +1, 0);
			mlx_delete_image(game->mlx, game->img->p);
			game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
			mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
		}
		if (keydata.key	== MLX_KEY_A && is_possible_move(game, 0, -1)) // -------------- LEFT
		{
			move_it(game, 0, -1);
			mlx_delete_image(game->mlx, game->img->p);
			game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
			mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
		}
	}
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_state	*game;

	game = (t_state *) param;
	move_character(keydata, game);// - - - - - - - - - - remove every other key possibility
	control_window(keydata, game);
	state_print(game);
}







// static void	move_character(mlx_key_data_t keydata, t_state *game)
// {
// 	if (keydata.action == MLX_PRESS)
// 	{
// 		if (keydata.key	== MLX_KEY_W && is_possible_move(game, -1, 0)) // -------------- UP
// 		{
// 			move_it(game, -1, 0);
// 			game->img->p->instances[0].y -= 64;
// 			// game->img->ground->instances[game->p.behind].y += 64;
// 			// game->p.behind -= 1;
// 		}
// 		if (keydata.key	== MLX_KEY_D && is_possible_move(game, 0, +1)) // -------------- RIGHT
// 		{
// 			move_it(game, 0, +1);
// 			game->img->p->instances[0].x += 64;
// 			// game->img->ground->instances[game->p.behind + 1].x -= 64;
// 			// game->p.behind += 1;
// 		}
// 		if (keydata.key	== MLX_KEY_S && is_possible_move(game, +1, 0)) // -------------- DOWN
// 		{
// 			move_it(game, +1, 0);
// 			game->img->p->instances[0].y += 64;
// 			// game->img->ground->instances[game->p.behind + 1].y -= 64;
// 			// game->p.behind += 1;
// 		}
// 		if (keydata.key	== MLX_KEY_A && is_possible_move(game, 0, -1)) // -------------- LEFT
// 		{
// 			move_it(game, 0, -1);
// 			game->img->p->instances[0].x -= 64;
// 			// game->img->ground->instances[game->p.behind - 1].y += 64;
// 			// game->p.behind -= 1;
// 		}
// 	}
// }

