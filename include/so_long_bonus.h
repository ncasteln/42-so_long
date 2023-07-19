/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:20:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/19 15:32:01 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libnc.h"
# include "MLX42.h"
# include "so_long_struct_bonus.h"
# include <fcntl.h>	// open() and close() fd
# include <math.h>	// rand() func

# ifndef WIDTH_LIMIT
#  define WIDTH_LIMIT 2560
# endif
# ifndef HEIGHT_LIMIT
#  define HEIGHT_LIMIT 1440
# endif

// ------------------------------------------------------------------ VALIDATION
int		validate(int argc, char **argv, t_state *game);
int		is_valid_format(t_list *lst, t_state *game);
int		is_valid_path(t_state *game);

// ---------------------------------------------------------------------- WINDOW
int		init_window(t_state *game);

// --------------------------------------------------------------- KEYS & EVENTS
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_event(void *param);

// -------------------------------------------------------------------- MESSAGES
void	display_steps(t_state *game);
void	display_end(t_state *game);

// ------------------------------------------------------------------------- MAP
int		draw_map(void *param);
void	redraw_items(t_state *game, char c);

// ----------------------------------------------------------------------- MOVES
int		is_possible_move(t_state *game, int y, int x, char c);
void	pc_move(t_state *game, int y, int x);
void	npc_move(t_state *game);

// ----------------------------------------------------------------------- UTILS
void	free_all(t_state *game);
void	lst_delnode(void *line);
void	err_print(t_state *game, int err_code);
void	state_print(t_state *game);
void	lst_print(t_list *lst);
char	**lst_to_dptr(t_list *lst, int y);

#endif
