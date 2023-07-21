/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:18:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 10:51:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_first_last_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '1')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

/* Returns (1) if there is already the element, otherwise set its coordinates */
static int	is_double(char c, t_state *game, int y, int x)
{
	if (c == 'P')
	{
		if (game->data.p.x || game->data.p.y)
			return (1);
		game->data.p.y = y;
		game->data.p.x = x;
	}
	if (c == 'E')
	{
		if (game->data.e)
			return (1);
		game->data.e += 1;
	}
	return (0);
}

static int	is_valid_item(char c)
{
	if (c == 'P' || c == '1' || c == 'E' || c == '0' || c == 'C')
		return (1);
	return (0);
}

static void	is_valid_mid_line(const char *line, t_state *game, int y)
{
	size_t		x;

	x = 0;
	ft_printf("line %s\n", line);
	while (line[x])
	{
		if ((x == 0) && (line[x] != '1'))
			return (err_print(game, INV_FORMAT));
		if ((x > 0 && x < ft_strlen(line) - 2))
		{
			if (!is_valid_item(line[x]))
				return (err_print(game, INV_ITEM));
			if (line[x] == 'P' && is_double('P', game, y, x))
				return (err_print(game, DOUB_ITEM));
			if (line[x] == 'E' && is_double('E', game, y, x))
				return (err_print(game, DOUB_ITEM));
			if (line[x] == 'C')
				game->data.c += 1;
		}
		if ((x == ft_strlen(line) - 2) && (line[x] != '1'))
			return (err_print(game, INV_FORMAT));
		x++;
	}
}

static int	is_rectangle(t_list *lst)
{
	size_t	line_len;

	line_len = ft_strlen(lst->content);
	lst = lst->next;
	while (lst->next)
	{
		if (!(line_len == ft_strlen(lst->content)))
			return (0);
		lst = lst->next;
	}
	if (!(line_len == ft_strlen(lst->content)))
		return (0);
	return (1);
}

/* This function check the line format and call other functions which
check other validation requirements (n of items, kind of items etc.) */
static void	is_valid_line(t_state *game)
{
	int		y;
	t_list	*temp;

	temp = game->data.lines;
	if (!(is_valid_first_last_line(temp->content)))
		return (err_print(game, INV_FORMAT));
	y = 1;
	temp = temp->next;
	while (temp->next)
	{
		is_valid_mid_line(temp->content, game, y);
		temp = temp->next;
		y++;
	}
	if (!(is_valid_first_last_line(temp->content)))
		return (err_print(game, INV_FORMAT));
}

void	is_valid_format(t_state *game)
{
	is_valid_line(game);
	if (!(game->data.p.x) || !(game->data.e) || !(game->data.c))
		return (err_print(game, MISS_ITEM));
	if (!is_rectangle(game->data.lines))
		return (err_print(game, INV_MAPSHAPE));
}
