/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:54:11 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/10 11:47:46 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_exit(const char *s, char *file_name, const char *func_name, int line)
{
	ft_printf("Error\n");
	ft_printf("%s @ line [%d] | %s() in [%s]\n", s, line, func_name, file_name);
	exit(1);
}
