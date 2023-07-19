/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 09:37:01 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_state	game;

	ft_bzero(&game, sizeof(t_state));
	validate(argc, argv, &game);
	init_window(&game);
	mlx_key_hook(game.mlx, handle_key, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
	// free_all(&game); // --- --- --- -- needed ???
	// mlx_terminate(game.mlx);
	system("leaks so_long");
	return (0);
}
