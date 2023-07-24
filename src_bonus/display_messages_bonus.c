/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 16:25:19 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_end(t_state *game)
{
	int			mid_y;
	int			mid_x;
	mlx_image_t	*end_img;

	end_img = game->img->end_img;
	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [Esc]") * 10) / 2);
	end_img = mlx_put_string(game->mlx, "Game Over [Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	char	*temp_1;
	char	*temp_2;
	t_data	*data;

	data = game->data;
	data->steps += 1;
	if (data->steps_str)
		free(data->steps_str);
	temp_1 = ft_strdup("Steps: ");
	temp_2 = ft_itoa(data->steps);
	data->steps_str = ft_strjoin(temp_1, temp_2);
	free(temp_1);
	free(temp_2);
	mlx_delete_image(game->mlx, game->img->steps_img);
	game->img->steps_img = mlx_put_string(game->mlx, data->steps_str, 24, 24);
}
