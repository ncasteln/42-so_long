/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:07:27 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 08:49:57 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_err_str(int err_code)
{
	if (err_code == INV_ARG)
		return ("Invalid arguments");
	if (err_code == READ_LST_FAIL)
		return ("Fail during file reading or lst creation");
	if (err_code == INV_FORMAT)
		return ("Invalid line format");
	if (err_code == INV_ITEM)
		return ("Invalid item found");
	if (err_code == DOUB_ITEM)
		return ("Double item found");
	if (err_code == MISS_ITEM)
		return ("Double item found");
	if (err_code == INV_MAPSHAPE)
		return ("Map is not rectangular");
	if (err_code == MAP_FAIL)
		return ("Map creation failed");
	if (err_code == INV_PATH)
		return ("Invalid path");
	if (err_code == INV_MAPSIZE) //??
		return ("Map too big");
	if (err_code == FAIL_IMGTEXT)
		return ("Failed init texture / images");
	return ("Unknow error");
}

void	err_print(t_state *game, int err_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(get_err_str(err_code), 2); // ------------- to fd 2 ???
	free_all(game); // mlx terminate and close window ??? --- needed ????
	exit(EXIT_FAILURE);
}

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	game->steps += 1;
	ft_printf("Steps: %d\n", game->steps);
}
