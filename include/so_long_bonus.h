/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:20:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 13:06:10 by ncasteln         ###   ########.fr       */
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
	MLX_IMG_FAIL,
	MLX_IMGWIN_FAIL
};

// ------------------------------------------------------------------ VALIDATION
void	validate(int argc, char **argv, t_data *data);
void	is_valid_format(t_data *data);
void	is_valid_path(t_data *data);
void	del_line(void *line);
int		is_duplicate_item(char c, t_data *data, int y, int x);
int		is_valid_item(char c);
void	lst_print(t_list *lst);
char	**lst_to_dptr(t_list *lst, int y);

// ---------------------------------------------------------------------- WINDOW
void	init_window(t_state *game);
int		init_textures(t_state *game);
int		init_img(t_state *game);

// --------------------------------------------------------------- KEYS & EVENTS
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_event(void *param);

// -------------------------------------------------------------------- MESSAGES
void	display_steps(t_state *game);
void	display_end(t_state *game);

// ------------------------------------------------------------------------- MAP
void	draw_map(void *param);
void	redraw_items(t_state *game, char c);
void	reset_image(t_state *game, char c);

// ----------------------------------------------------------------------- MOVES
int		is_possible_move(t_state *game, int y, int x, char c);
void	p_move(t_state *game, int y, int x);
void	n_move(t_state *game);

// ----------------------------------------------------------------------- UTILS
void	free_state(t_state *game);
void	free_data(t_data *data);
void	err_print(int err_code);
void	state_print(t_state *game);

#endif
