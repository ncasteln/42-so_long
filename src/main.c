/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:23:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 11:12:45 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_state	game;
	t_data	data;

	ft_bzero(&game, sizeof(t_state));
	ft_bzero(&data, sizeof(t_data));
	validate(argc, argv, &data);
	game.data = &data;
	init_window(&game);
	mlx_key_hook(game.mlx, handle_key, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
	free_state(&game);
	return (EXIT_SUCCESS);
}
