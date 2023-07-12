/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:17:53 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 15:42:44 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	state_print(t_state *game)
{
	ft_printf("_________ GAME STATE _________\n");
	ft_printf("Player [%d][%d]\n", game->p.y, game->p.x);
	ft_printf("Exit: [%d]\n", game->c);
	ft_printf("Collectibles: [%d]\n", game->c);
	ft_printf("\nMap\n");
	nc_dptr_print(game->map);
}
