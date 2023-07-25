/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:05:37 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/25 09:06:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	reset_p_image(t_state *game)
{
	mlx_delete_image(game->mlx, game->img->p);
	if (!game->data->is_end)
	{
		if (game->data->p_last == 'r' || !game->data->p_last)
		{
			if (game->data->is_exit)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->pe_r);
			else
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->p_r);
		}
		else if (game->data->p_last == 'l')
		{
			if (game->data->is_exit)
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->pe_l);
			else
				game->img->p = mlx_texture_to_image(game->mlx, game->txt->p_l);
		}
	}
	else
		game->img->p = mlx_texture_to_image(game->mlx, game->txt->e_1);
}

void	reset_image(t_state *game, char c)
{
	t_img	*img;
	t_data	*data;

	img = game->img;
	data = game->data;
	if (c == 'C')
	{
		mlx_delete_image(game->mlx, img->c);
		img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	}
	else if (c == 'P')
		reset_p_image(game);
	else if (c == 'N')
	{
		mlx_delete_image(game->mlx, game->img->n);
		game->img->n = mlx_texture_to_image(game->mlx, game->txt->n);
	}
	else if (c == 'E')
	{
		mlx_delete_image(game->mlx, img->e);
		img->e = mlx_texture_to_image(game->mlx, game->txt->e_1);
	}
}
