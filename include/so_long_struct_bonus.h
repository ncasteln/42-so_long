/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:23:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 12:49:43 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_BONUS_H
# define SO_LONG_STRUCT_BONUS_H
# include "MLX42.h"

// -------------------------------------------------------------------- TEXTURES
typedef struct s_txt
{
	mlx_texture_t	*p_r;
	mlx_texture_t	*p_l;
	mlx_texture_t	*pe_r;
	mlx_texture_t	*pe_l;
	mlx_texture_t	*e_0;
	mlx_texture_t	*e_1;
	mlx_texture_t	*n;
	mlx_texture_t	*ne;
	mlx_texture_t	*c;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
}				t_txt;

// ---------------------------------------------------------------------- IMAGES
typedef struct s_img
{
	mlx_image_t	*p;
	mlx_image_t	*n;
	mlx_image_t	*e;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
	mlx_image_t	*steps_img;
	mlx_image_t	*end_img;
}			t_img;

// ---------------------------------------------------------------------- PLAYER
typedef struct s_char
{
	int			y;
	int			x;
}				t_char;

// ------------------------------------------------------------------ GAME STATE
/*
@ struct s_char	p;			player pos
@ char			p_last;		last direction of player
@ struct s_char	n;			enemy
@ int 			e;			n of exit
@ int			is_exit;	exit tile occupied by pc(1) or npc(2)
@ int			c;			n of collectibles
@ int			counter;	generic counter used inside mlx_loop_hook
@ char			**map;
@ int			steps;		n of steps done
@ char			*steps_str;	steps in string format to display
@ int			is_end;		if the game is over
@ struct s_img	*img;		ptr images of the game
@ struct s_txt	*txt;		ptr to textures of the game
@ mlx_t			*mlx;		ptr mlx structure
// */

// ------------------------------------------------------------------ DATA STATE
typedef struct s_data
{
	struct s_char	p;
	char			p_last;
	int				e;
	int				c;
	struct s_char	n;
	struct s_list	*lines;
	char			**map;
	int				steps;
	char			*steps_str;
	int				is_end;
	int				is_exit;
	int				counter;
}				t_data;

// ------------------------------------------------------------------ GAME STATE
typedef struct s_state
{
	struct s_data	*data;
	mlx_image_t		*end_img;
	struct s_img	*img;
	struct s_txt	*txt;
	mlx_t			*mlx;
}				t_state;

#endif
