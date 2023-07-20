/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:21:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 13:34:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_valid.h"

void	lst_delnode(void *line)
{
	if (line)
		free(line);
}

void	free_all(t_state *game)
{
	if (game->map)
		nc_dptr_free(game->map);
	// ft_bzero(&game, sizeof(t_state));
}
