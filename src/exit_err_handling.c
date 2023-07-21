/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:50:12 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:51:21 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_err_mlx(int err_code)
{
	if (err_code == MLX_FAIL)
		return ("Failed init window");
	if (err_code == MLX_IMG_FAIL)
		return ("Failed mlx image / textures");
	if (err_code == MLX_IMGWIN_FAIL)
		return ("Failed put img to window");
	return ("Unknow error");
}

static char	*get_err_str(int err_code)
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
		return ("An item is missing");
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
	return ("Unknow error");
}

void	err_print(int err_code)
{
	ft_putendl_fd("Error", 2);
	if (err_code < 11)
		ft_putendl_fd(get_err_str(err_code), 2);
	else
		ft_putendl_fd(get_err_mlx(err_code), 2);
	exit (EXIT_FAILURE);
}
