/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 14:09:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*set_images(mlx_t *mlx)
{
	t_img *img;
	t_txt *txt;

	img = malloc (sizeof(t_img) * 5); // protect

	txt = malloc (sizeof(mlx_texture_t) * 5); // protect
	txt->p = mlx_load_png("./textures/player.png");
	txt->e = mlx_load_png("./textures/exit.png");
	txt->c = mlx_load_png("./textures/coll.png");
	txt->ground = mlx_load_png("./textures/ground.png");
	txt->wall = mlx_load_png("./textures/wall.png");

	img->p = mlx_texture_to_image(mlx, txt->p);
	img->e = mlx_texture_to_image(mlx, txt->e);
	img->c = mlx_texture_to_image(mlx, txt->c);
	img->ground = mlx_texture_to_image(mlx, txt->ground);
	img->wall = mlx_texture_to_image(mlx, txt->wall);
	// clean and free textures if not needed // if needed put inside t_state
	return (img);
}

void	build_map(void *param)
{
	int			y;
	int			x;
	t_state 	*game;


	game = (t_state *) param;
	game->txt = malloc (sizeof(mlx_texture_t) * 5); // protect
	game->txt->p = mlx_load_png("./textures/player.png");
	game->txt->e = mlx_load_png("./textures/exit.png");
	game->txt->c = mlx_load_png("./textures/coll.png");
	game->txt->ground = mlx_load_png("./textures/ground.png");
	game->txt->wall = mlx_load_png("./textures/wall.png");

	game->img = malloc (sizeof(t_img) * 5); // protect
	game->img->p = mlx_texture_to_image(game->mlx, game->txt->p);
	game->img->e = mlx_texture_to_image(game->mlx, game->txt->e);
	game->img->c = mlx_texture_to_image(game->mlx, game->txt->c);
	game->img->ground = mlx_texture_to_image(game->mlx, game->txt->ground);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);

	y = 0;
	while (y < nc_dptr_size_y(game->map))
	{
		x = 0;
		while (x < nc_dptr_size_x(game->map))
		{
			mlx_image_to_window(game->mlx, game->img->ground, x * 64, y * 64);
			if (game->map[y][x] == '1')
			{
				mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
			}
			if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->img->c, x * 64, y * 64);
			}
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->img->e, x * 64, y * 64);
			}
			if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->img->p, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}








// ?????
// void	build_map(void *param)
// {
// 	int			y;
// 	int			x;
// 	t_state 	*game;
// 	int32_t		curr_inst;
// 	int			counter = 0;

// 	game = (t_state *) param;
// 	// game->img = set_images(game->mlx);
// 	y = 0;
// 	0;
// 	while (y < nc_dptr_size_y(game->map))
// 	{
// 		x = 0;
// 		while (x < nc_dptr_size_x(game->map))
// 		{
// 			if (game->map[y][x] == '0')
// 			{
// 				game->image = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/ground.png"));
// 				mlx_image_to_window(game->mlx, game->image, x * 64, y * 64);
// 			}
// 			if (game->map[y][x] == '1')
// 			{
// 				game->image = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/wall.png"));
// 				mlx_image_to_window(game->mlx, game->image, x * 64, y * 64);
// 			}
// 			if (game->map[y][x] == 'C')
// 			{
// 				game->image = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/coll.png"));
// 				mlx_image_to_window(game->mlx, game->image, x * 64, y * 64);
// 			}
// 			if (game->map[y][x] == 'E')
// 			{
// 				game->image = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/exit.png"));
// 				mlx_image_to_window(game->mlx, game->image, x * 64, y * 64);
// 			}
// 			if (game->map[y][x] == 'P')
// 			{
// 				game->image = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player.png"));
// 				mlx_image_to_window(game->mlx, game->image, x * 64, y * 64);
// 			}
// 			ft_printf("cu  rr_inst = [%d]\n", curr_inst);
// 			x++;
// 		}
// 		y++;
// 	}
// }










// MAYBE SOMETHIGN LIKE THIS WITH A UNIQUE INSTANCE ????
// void	build_map(void *param)
// {
// 	int			y;
// 	int			x;
// 	t_state 	*game;
// 	int32_t		curr_inst;
// 	int			counter = 0;


// 	game = (t_state *) param;
// 	game->img = set_images(game->mlx);
// 	y = 0;
// 	0;
// 	while (y < nc_dptr_size_y(game->map))
// 	{
// 		x = 0;
// 		while (x < nc_dptr_size_x(game->map))
// 		{
// 			if (game->map[y][x] == '0')
// 				curr_inst= mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, mlx_load_png("./textures/ground.png")), x * 64, y * 64);
// 			if (game->map[y][x] == '1')
// 				curr_inst= mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, mlx_load_png("./textures/wall.png")), x * 64, y * 64);
// 			if (game->map[y][x] == 'C')
// 				curr_inst= mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, mlx_load_png("./textures/coll.png")), x * 64, y * 64);
// 			if (game->map[y][x] == 'E')
// 				curr_inst= mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, mlx_load_png("./textures/exit.png")), x * 64, y * 64);
// 			if (game->map[y][x] == 'P')
// 				curr_inst= mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player.png")), x * 64, y * 64);
// 			ft_printf("cu  rr_inst = [%d]\n", curr_inst);
// 			x++;
// 		}
// 		y++;
// 	}
// }





