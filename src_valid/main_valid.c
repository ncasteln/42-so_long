/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:10:09 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 12:49:37 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_valid.h"

int	main(int argc, char **argv)
{
	t_state game;

	validate(argc, argv, &game);
	free_all(&game);
	return (0);
}
