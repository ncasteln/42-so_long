/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 08:39:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	t_state	game;

	ft_bzero(&game, sizeof(t_state));
	if (!validate(argc, argv, &game))
		return (free_all(&game), err_print(1));
	if (!init_window(&game))
		return (free_all(&game), err_print(2));
	mlx_loop_hook(game.mlx, handle_event, &game);
	mlx_key_hook(game.mlx, handle_key, &game);
	if (!draw_map(&game))
		return (free_all(&game), err_print(3));
	mlx_loop(game.mlx);
	free_all(&game);
	mlx_terminate(game.mlx);
	// system("leaks so_long_bonus");
	return (0);
}
