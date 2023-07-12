/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:39:32 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/10 10:59:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNC_H
# define LIBNC_H
# include "libft.h"
# include "ft_printf.h"

int		nc_is_valid_ext(const char *s, const char *ext);
void	nc_exit(const char *s, char *file_name, const char *func_name, int line);
int		nc_dptr_size_y(char **s);
int		nc_dptr_size_x(char **s);
char	**nc_dptr_deepcpy(char **p);
void	nc_dptr_free(char **p);
void	nc_dptr_print(char **p);

#endif
