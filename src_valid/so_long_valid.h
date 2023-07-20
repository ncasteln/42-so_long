/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:05:26 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 12:34:12 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_VALID_H
# define SO_LONG_VALID_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libnc.h"
# include <fcntl.h>	// open() and close() fd

// ---------------------------------------------------------------------- ERRORS
enum e_err_code
{
	INV_ARG,
	READ_LST_FAIL,
	INV_FORMAT,
	INV_ITEM,
	DOUB_ITEM,
	MISS_ITEM,
	INV_MAPSHAPE,
	MAP_FAIL,
	INV_PATH,
	INV_MAPSIZE,
	FAIL_IMGTEXT,
	MLX_FAIL,
	MLX_IMGWIN_FAIL
};

// ---------------------------------------------------------------------- PLAYER
typedef struct s_char
{
	int			y;
	int			x;
}				t_char;

// ------------------------------------------------------------------ GAME STATE
typedef struct s_state
{
	struct s_char	p;
	int				is_exit;
	int				e;
	int				c;
	char			**map;
	int				steps;
	int				is_end;
}				t_state;

// ------------------------------------------------------------------ VALIDATION
void	validate(int argc, char **argv, t_state *game);
void	is_valid_format(t_list *lst, t_state *game);
void	is_valid_path(t_state *game);

// ---------------------------------------------------------------------- WINDOW
void	init_window(t_state *game);

// --------------------------------------------------------------- KEYS & EVENTS
void	handle_event(void *param);

// -------------------------------------------------------------------- MESSAGES
void	display_end(t_state *game);
void	display_steps(t_state *game);

// ------------------------------------------------------------------------- MAP
int		draw_map(void *param);
void	redraw_items(t_state *game, char c);

// ----------------------------------------------------------------------- UTILS
void	free_all(t_state *game);
void	lst_delnode(void *line);
void	state_print(t_state *game);
void	lst_print(t_list *lst);
char	**lst_to_dptr(t_list *lst, int y);
void	err_print(t_state *game, int err_code);

#endif
