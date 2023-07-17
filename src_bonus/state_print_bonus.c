/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:17:53 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 11:09:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	state_print(t_state *game)
{
	ft_printf("_________ GAME STATE _________\n");
	ft_printf("Player [%d][%d]\n", game->p.y, game->p.x);
	ft_printf("Exit: [%d]\n", game->c);
	ft_printf("Collectibles: [%d]\n", game->c);
	ft_printf("Last was exit: [%d]\n", game->is_exit);
	ft_printf("\nMap\n");
	nc_dptr_print(game->map);
}
