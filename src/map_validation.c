/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:18:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/20 14:16:08 by ncasteln         ###   ########.fr       */
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
		if (game->p.x || game->p.y)
			return (1);
		game->p.y = y;
		game->p.x = x;
	}
	if (c == 'E')
	{
		if (game->e)
			return (1);
		game->e += 1;
	}
	return (0);
}

static int	is_valid_item(char c)
{
	if (c == 'P' || c == '1' || c == 'E' || c == '0' || c == 'C')
		return (1);
	return (0);
}

static void	is_valid_mid_line(t_list **lst, t_state *game, int y)
{
	size_t		x;
	const char	*curr_line;

	x = 0;
	curr_line = (*lst)->content;
	while (curr_line[x])
	{
		if ((x == 0) && (curr_line[x] != '1'))
			return (ft_lstclear(lst, lst_delnode), err_print(game, INV_FORMAT));
		if ((x > 0 && x < ft_strlen(curr_line) - 2))
		{
			if (!is_valid_item(curr_line[x]))
				return (ft_lstclear(lst, lst_delnode), err_print(game, INV_ITEM));
			if (curr_line[x] == 'P' && is_double('P', game, y, x))
				return (ft_lstclear(lst, lst_delnode), err_print(game, DOUB_ITEM));
			if (curr_line[x] == 'E' && is_double('E', game, y, x))
				return (ft_lstclear(lst, lst_delnode), err_print(game, DOUB_ITEM));
			if (curr_line[x] == 'C')
				game->c += 1;
		}
		if ((x == ft_strlen(curr_line) - 2) && (curr_line[x] != '1'))
			return (ft_lstclear(lst, lst_delnode), err_print(game, INV_FORMAT));
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
static void	is_valid_line(t_state *game, t_list *lst)
{
	int	y;

	if (!(is_valid_first_last_line(lst->content)))
		return (ft_lstclear(&lst, lst_delnode), err_print(game, INV_FORMAT));
	lst = lst->next;
	y = 0;
	while (lst->next)
	{
		y++;
		is_valid_mid_line(&lst, game, y); // more specific
		// if (!is_valid_mid_line(lst->content, game, y)) // more specific
		// 	return (ft_lstclear(&lst, lst_delnode), err_print(game, INV_FORMAT));
		lst = lst->next;
	}
	if (!(is_valid_first_last_line(lst->content)))
		return (ft_lstclear(&lst, lst_delnode), err_print(game, INV_FORMAT));
}

void	is_valid_format(t_list *lst, t_state *game)
{
	is_valid_line(game, lst);
	if (!(game->p.x) || !(game->e) || !(game->c))
		return (ft_lstclear(&lst, lst_delnode), err_print(game, MISS_ITEM));
	if (!is_rectangle(lst))
		return (ft_lstclear(&lst, lst_delnode), err_print(game, INV_MAPSHAPE));
}
