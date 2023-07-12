/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dptr_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:58:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/10 11:01:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_dptr_print(char **p)
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
