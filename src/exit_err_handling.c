/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:50:12 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 12:28:32 by ncasteln         ###   ########.fr       */
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
	if (err_code == INV_MAPSIZE)
		return ("Map too big");
	if (err_code == FAIL_IMGTEXT)
		return ("Failed init texture / images");
	if (err_code == MLX_FAIL)
		return ("Failed init window");
	if (err_code == MLX_IMGWIN_FAIL)
		return ("Failed put img to window");
	return ("Unknow error");
}

void	err_print(t_state *game, int err_code)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(get_err_str(err_code), 2);
	free_all(game); // ------------------------------------ needed ????
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
