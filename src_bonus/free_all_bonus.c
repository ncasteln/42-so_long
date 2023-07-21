/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:21:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 16:46:59 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	del_line(void *line)
{
	if (line)
		free(line);
}

static void	free_images(mlx_t *mlx, t_img *img)
{
	mlx_delete_image(mlx, img->p);
	mlx_delete_image(mlx, img->c);
	mlx_delete_image(mlx, img->e);
	mlx_delete_image(mlx, img->n);
	mlx_delete_image(mlx, img->ground);
	mlx_delete_image(mlx, img->wall);
	mlx_delete_image(mlx, img->steps_img);
	mlx_delete_image(mlx, img->end_img);
	free(img);
}

static void	free_textures(t_txt *txt)
{
	mlx_delete_texture(txt->p_r);
	mlx_delete_texture(txt->p_l);
	mlx_delete_texture(txt->pe_r);
	mlx_delete_texture(txt->pe_l);
	mlx_delete_texture(txt->e_0);
	mlx_delete_texture(txt->e_1);
	mlx_delete_texture(txt->c);
	mlx_delete_texture(txt->n);
	mlx_delete_texture(txt->ne);
	mlx_delete_texture(txt->ground);
	mlx_delete_texture(txt->wall);
	free(txt);
}

void	free_state(t_state *game)
{
	if (game->data)
		free_data(game->data);
	if (game->txt)
		free_textures(game->txt);
	if (game->img)
		free_images(game->mlx, game->img);
	if (game->end_img)
		mlx_delete_image(game->mlx, game->end_img);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	free_data(t_data *data)
{
	if (data->map)
		nc_dptr_free(data->map);
	if (data->lines)
		ft_lstclear(&data->lines, del_line);
	if (data->steps_str)
		free(data->steps_str);
}
