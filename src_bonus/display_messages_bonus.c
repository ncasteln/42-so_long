/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 09:35:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	err_print(int err)
{
	ft_putendl_fd("Error", 2);
	if (err == 1)
		ft_putendl_fd("Invalid map", 2);
	if (err == 2)
		ft_putendl_fd("MLX failed", 2);
	if (err == 3)
		ft_putendl_fd("Map building failed", 2);
	return (err);
}

void	display_end(t_state *game)
{
	int	mid_y;
	int	mid_x;

	mid_y = (game->mlx->height / 2) - 10;
	mid_x = (game->mlx->width / 2) - ((ft_strlen("Game Over [press Esc]") * 10) / 2);
	game->img->end_img = mlx_put_string(game->mlx, "Game Over [press Esc]", mid_x, mid_y);
}

void	display_steps(t_state *game)
{
	char	*temp_1;
	char	*temp_2;

	game->steps += 1;
	if (game->steps_str)
		free(game->steps_str);
	temp_1 = ft_strdup("Steps: ");
	temp_2 = ft_itoa(game->steps);
	game->steps_str = ft_strjoin(temp_1, temp_2);
	free(temp_1);
	free(temp_2);
	redraw_items(game, 'S');
}
