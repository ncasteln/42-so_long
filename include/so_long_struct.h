/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:23:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 17:51:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H
# include "so_long.h"

// -------------------------------- TEXTURES -----------------------------------
typedef struct	s_txt
{
	mlx_texture_t	*p;
	mlx_texture_t	*e;
	mlx_texture_t	*c;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
	mlx_texture_t	*enemy;
}				t_txt;

// ---------------------------------- IMAGES -----------------------------------
typedef struct s_img
{
	mlx_image_t	*p;
	mlx_image_t	*e;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
	mlx_image_t	*enemy;
}			t_img;

// ---------------------------------- PLAYER -----------------------------------
typedef struct s_player
{
	int				y;
	int				x;
}				t_player;

// -------------------------------- GAME STATE ---------------------------------
typedef struct s_state
{
	struct s_player	p;
	int				e;
	int				c;
	char			**map;
	mlx_t			*mlx;
	struct	s_img	*img;
	struct	s_txt	*txt;
	int				steps;
}				t_state;

#endif
