/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:23:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 15:45:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H
# include "MLX42.h"

// -------------------------------------------------------------------- TEXTURES
typedef struct s_txt
{
	mlx_texture_t	*p;
	mlx_texture_t	*e_0;
	mlx_texture_t	*e_1;
	mlx_texture_t	*pe_r;
	mlx_texture_t	*c;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
}				t_txt;

// ---------------------------------------------------------------------- IMAGES
typedef struct s_img
{
	mlx_image_t	*p;
	mlx_image_t	*e;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
}				t_img;

// ---------------------------------------------------------------------- PLAYER
typedef struct s_char
{
	int			y;
	int			x;
}				t_char;

// ------------------------------------------------------------------ DATA STATE
typedef struct s_data
{
	struct s_char	p;
	int				e;
	int				c;
	struct s_list	*lines;
	char			**map;
	int				steps;
	int				is_end;
	int				is_exit;
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
