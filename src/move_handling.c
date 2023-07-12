/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:08:03 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 17:51:12 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_steps(t_state *game)
{
	const char *steps;

	game->steps += 1;
	ft_printf("Steps done: %d\n", game->steps);
	game->img->wall = mlx_put_string(game->mlx, "Steps: ", game->mlx->width / 64, game->mlx->height / 64);
}

static void	redraw_collectibles(t_state *game)
{
	int	y;
	int	x;

	mlx_delete_image(game->mlx, game->img->c);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);

	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	update_map(t_state *game, int next_p_y, int next_p_x)
{
	game->map[game->p.y][game->p.x] = '0'; 	// put groudn on plpace of player
	game->p.y = next_p_y;					// change player position
	game->p.x = next_p_x;
	game->map[next_p_y][next_p_x] = 'P';	// put player tile on new player position
}

/* The function accept the inverement value of each coordinate */
void	move_player(t_state *game, int y, int x)
{
	int	next_p_x;
	int	next_p_y;

	next_p_x = game->p.x + x;
	next_p_y = game->p.y + y;
	if (game->map[next_p_y][next_p_x] == 'C')
	{
		game->c -= 1;
		update_map(game, next_p_y, next_p_x);
		redraw_collectibles(game);
	}
	else if (game->map[next_p_y][next_p_x] == '0')
		update_map(game, next_p_y, next_p_x);
	else if (game->map[next_p_y][next_p_x] == '!')
	{
		ft_printf(" ***** GAME OVER ****\n");
		exit(1);
	}
}

void	handle_move(t_state *game, int y, int x)
{
	move_player(game, y, x);
	mlx_delete_image(game->mlx, game->img->p);
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	mlx_image_to_window(game->mlx, game->img->p, game->p.x * 64, game->p.y * 64);
}

int	is_possible_move(t_state *game, int y, int x)
{
	int	next_p_y;
	int	next_p_x;
	int	cell;

	set_steps(game);
	next_p_y = game->p.y + y;
	next_p_x = game->p.x + x;
	cell = game->map[next_p_y][next_p_x];
	if (cell == '0' || cell == 'C' || cell == '!')
		return (1);
	if (cell == 'E' && game->c == 0)
	{
		exit (1);  // -------------------------- game finished !!
		return (1);
	}
	return (0);
}

