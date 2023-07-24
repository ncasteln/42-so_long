/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 16:31:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	t_state	game;
	t_data	data;

	ft_bzero(&game, sizeof(t_state));
	ft_bzero(&data, sizeof(t_data));
	validate(argc, argv, &data);
	game.data = &data;
	init_window(&game);
	mlx_loop_hook(game.mlx, handle_event, &game);
	mlx_key_hook(game.mlx, handle_key, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
	free_state(&game);
	return (0);
}
