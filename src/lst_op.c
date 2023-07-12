/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:11:01 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/06 16:11:31 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lst_print(t_list *lst) // ------------ export function
{
	int i = 0;
	while (lst && lst->next)
	{
		ft_printf("line [%d] %s", i, lst->content);
		lst = lst->next;
		i++;
	}
	ft_printf("line [%d] %s", i, lst->content);
}
