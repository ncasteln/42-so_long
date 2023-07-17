/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:23:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/17 13:18:28 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H
#include "so_long_bonus.h"

// -------------------------------- TEXTURES -----------------------------------
typedef struct	s_txt
{
	mlx_texture_t	*p;
	mlx_texture_t	*n;
	mlx_texture_t	*e;
	mlx_texture_t	*c;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
}				t_txt;

// ---------------------------------- IMAGES -----------------------------------
typedef struct s_img
{
	mlx_image_t	*p;
	mlx_image_t	*n;
	mlx_image_t	*e;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
	mlx_image_t	*steps;
}			t_img;

// ---------------------------------- PLAYER -----------------------------------
typedef struct s_char
{
	int			y;
	int			x;
}				t_char;

// -------------------------------- GAME STATE ---------------------------------
typedef struct s_state
{
	struct s_char	p;
	struct s_char	n;
	int				e;
	int				is_exit;
	int				c;
	int				counter;
	char			**map;
	int				steps;
	struct	s_img	*img;
	struct	s_txt	*txt;
	mlx_t			*mlx;
}				t_state;

#endif
