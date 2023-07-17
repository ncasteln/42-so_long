/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:18:38 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 10:51:11 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_error(int err)
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
