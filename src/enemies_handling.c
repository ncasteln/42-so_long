/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:09:59 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 12:24:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_n_ground(char **map)
{
	int	y;
	int	x;
	int	counter;

	counter = 0;
	y = 0;
	while (y < nc_dptr_size_y(map))
	{
		x = 0;
		while (x < nc_dptr_size_x(map))
		{
			if (map[y][x] == '0')
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void	position_enemy(t_state *game, int enemy_index)
{
	int	y;
	int	x;

	// enemy_index = 0 // change this to try exceptions
	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			if (game->map[y][x] == '0')
			{
				enemy_index--;
				if (enemy_index == 0)
					game->map[y][x] = '!';
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_state *game)
{
	int	n_ground;
	// int	*ground_indexes;
	int	enemy_index;

	n_ground = get_n_ground(game->map);
	// if (n_ground > 6) && possible path
	enemy_index = rand() % n_ground;
	position_enemy(game, enemy_index);

	// while (!is_valid_path(game))
	// {
	// 	enemy_index = rand() % n_ground;
	// 	nc_dptr_free(game->map);
	// 	game->map = map_cpy;
	// 	position_enemy(game, enemy_index);
	// }


	// 1) change is_valid_path = need to return 1 or 0 and not exit
	// 2) until is_valid_path returns (1) change the position of the enemy
			// this can be done either cpying the old map without it, or checking after is positioned
}
