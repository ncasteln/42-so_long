/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:07:27 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 12:28:08 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_valid.h"

void	display_steps(t_state *game)
{
	game->steps += 1;
	ft_printf("Steps: %d\n", game->steps);
}
