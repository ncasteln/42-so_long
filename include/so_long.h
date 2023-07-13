/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:20:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 15:40:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libnc.h"
# include "MLX42.h"
# include "so_long_struct.h"

# include <fcntl.h>

// ---------------------------------- WINDOW ------------------------------------
int		init_window(t_state *game);

// ----------------------------------- STATE ------------------------------------
void	state_print(t_state *game);

// -------------------------------- VALIDATION ---------------------------------
int		validate(int argc, char **argv, t_state *game);
int		is_valid_format(t_list *lst, t_state *game);
int		is_valid_path(t_state *game);

// ------------------------------------- MAP -----------------------------------
int		init_map(void *param);

// ------------------------------------- ENEMY ----------------------------------
// void	init_enemies(t_state *game);

// ------------------------------------ MOVES -----------------------------------
int		is_possible_move(t_state *game, int y, int x);
void	handle_move(t_state *game, int y, int x);
void	move_player(t_state *game, int y, int x);

// ------------------------------ KEYS & EVENTS --------------------------------
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_event(void *param);

// ------------------------------- OTHER UTILS ---------------------------------
void	lst_print(t_list *lst);
char	**lst_to_dptr(t_list *lst, int y);

// ------------------------------- ERR UTILS ---------------------------------
void	free_all(t_state *game);
void	lst_delnode(void *line);

#endif
