/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 17:51:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_state *game)
{
	game->map = NULL;
	game->p.y = 0;
	game->p.x = 0;
	game->e = 0;
	game->c = 0;
	game->mlx = NULL;
	game->img = NULL;
	game->txt = NULL;
	game->steps = 0;
}

static void	free_state(t_state *game)
{
	if (game->map)
		nc_dptr_free(game->map);
	// if (game->mlx)
		// mlx free()
}

int32_t	main(int argc, char **argv)
{
	t_state	game;

	init_game(&game);
	validate(argc, argv, &game);
	init_enemies(&game);
	init_window(&game);
	mlx_key_hook(game.mlx, handle_key, &game);
	// mlx_loop_hook(game.mlx, update_map, &game);
	init_map(&game);
	mlx_loop(game.mlx);
	free_state(&game); // ----- update
	// state_print(&game);
	// system("leaks so_long");
	return (0);
}
