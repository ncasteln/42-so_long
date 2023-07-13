/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 16:11:03 by ncasteln         ###   ########.fr       */
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

int32_t	main(int argc, char **argv)
{
	t_state	game;

	init_game(&game);
	if (!validate(argc, argv, &game))
		return (free_all(&game), 1);


	if (!init_window(&game))
		return (free_all(&game), 1);


	mlx_key_hook(game.mlx, handle_key, &game);
	if (!init_map(&game))
		return (free_all(&game), 1);
	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);
	free_all(&game); // ----- update
	// system("leaks so_long");
	return (0);
}

// init_enemies(&game);
	//
// mlx_loop_hook(game.mlx, update_map, &game);

