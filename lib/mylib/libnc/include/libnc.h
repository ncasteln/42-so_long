/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:39:32 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 10:25:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNC_H
# define LIBNC_H
# include "libft.h"
# include "ft_printf.h"

int		nc_is_valid_ext(const char *s, const char *ext);
int		nc_dptr_size_y(char **s);
int		nc_dptr_size_x(char **s);
char	**nc_dptr_deepcpy(char **p);
void	nc_dptr_free(char **p);
void	nc_dptr_print(char **p);
void	lst_print(t_list *lst);

#endif
