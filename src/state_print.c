/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:17:53 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/24 09:08:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dptr_print(char **p)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		ft_printf("line [%d] ", i);
		while (p[i][j])
		{
			ft_printf("%c", p[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	state_print(t_state *game)
{
	ft_printf("_________ GAME STATE _________\n");
	ft_printf("Player [%d][%d]\n", game->data->p.y, game->data->p.x);
	ft_printf("Exit: [%d]\n", game->data->c);
	ft_printf("Collectibles: [%d]\n", game->data->c);
	ft_printf("Last was exit: [%d]\n", game->data->is_exit);
	ft_printf("\nMap\n");
	if (game->data->map)
		dptr_print(game->data->map);
	else
		ft_printf(" *** No map to print ***\n");
}
