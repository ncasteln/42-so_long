/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:20:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/25 09:10:38 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "MLX42.h"
# include "so_long_struct.h"
# include <fcntl.h>	// open() and close() fd

// ----------------------------------------------------------------- SCREEN SIZE
# ifndef WIDTH_LIMIT
#  define WIDTH_LIMIT 2560
# endif
# ifndef HEIGHT_LIMIT
#  define HEIGHT_LIMIT 1440
# endif

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
	MLX_IMG_FAIL,
	MLX_IMGWIN_FAIL
};

// ------------------------------------------------------------------ VALIDATION
void	validate(int argc, char **argv, t_data *game);
void	is_valid_format(t_data *data);
int		is_valid_item(char c);
int		is_double_item(char c, t_data *data, int y, int x);
void	is_valid_path(t_data *game);
void	lst_print(t_list *lst);
char	**lst_to_dptr(t_list *lst, int y);
void	del_line(void *line);

// --------------------------------------------------------- INIT WIN, IMG & TXT
void	init_window(t_state *game);
int		init_textures(t_state *game);
int		init_img(t_state *game);

// --------------------------------------------------------------- KEYS & EVENTS
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_event(void *param);

// -------------------------------------------------------------------- MESSAGES
void	display_end(t_state *game);
void	display_steps(t_state *game);

// ------------------------------------------------------------------------- MAP
void	draw_map(void *param);
void	redraw_items(t_state *game, char c);

// ----------------------------------------------------------------------- MOVES
void	p_move(t_state *game, int y, int x);

// ------------------------------------------------------------------------ DPTR
int		dptr_size(char **s, char axis);
void	dptr_print(char **p);
char	**dptr_deepcpy(char **src);

// ----------------------------------------------------------------------- UTILS
void	dptr_free(char **p);
void	free_data(t_data *data);
void	free_state(t_state *game);
void	err_print(int err_code);
void	state_print(t_state *game);

#endif
