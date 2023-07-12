/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:20:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 15:25:37 by ncasteln         ###   ########.fr       */
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
void	init_window(t_state *game);

// ---------------------------------- IMAGES ------------------------------------
void	init_textures(t_state *game);

// ----------------------------------- STATE ------------------------------------
void	state_print(t_state *game);

// -------------------------------- VALIDATION ---------------------------------
void	validate(int argc, char **argv, t_state *game);
int		is_valid_line(t_list *lst, t_state *game);
int		is_valid_path(t_state *game);

// -------------------------------- COORDINATES ---------------------------------
// t_coord	*coord_new(int y, int x);
// void	coord_append(t_coord **coord, t_coord *new_node);
// void	coord_print(t_coord *coord);
// int		coord_size(t_coord *coord);
// void	coord_match(t_coord **coord, int y, int x);
// void	coord_clear(t_coord **coord);

// ------------------------------------- MAP -----------------------------------
void	build_map(void *param);
void	update_map(void *param);

// ------------------------------------ MOVES -----------------------------------
int		is_possible_move(t_state *game, int y, int x);
void	move_it(t_state *game, int y, int x);

// ------------------------------ KEYS & EVENTS --------------------------------
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_event(void *param);

// ------------------------------- OTHER UTILS ---------------------------------
void	lst_print(t_list *lst);
char	**lst_to_double_ptr(t_list *lst, int y);

#endif
