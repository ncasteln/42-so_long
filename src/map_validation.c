/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:18:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/13 15:34:32 by ncasteln         ###   ########.fr       */
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

static int	is_duplicate(char c, t_state *game, int y, int x)
{
	if (c == 'P')
	{
		if (game->p.x || game->p.y)
			return (0);
		game->p.y = y;
		game->p.x = x;
	}
	if (c == 'E')
	{
		if (game->e)
			return (0);
		else
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

static int	is_valid_mid_line(const char *curr_line, t_state *game, int y)
{
	size_t	x;

	x = 0;
	while (curr_line[x])
	{
		if ((x == 0) && (curr_line[x] != '1'))
			return (0);
		if ((x > 0 && x < ft_strlen(curr_line) - 2))
		{
			if (!is_valid_item(curr_line[x]))
				return (0);
			if (curr_line[x] == 'P')
				is_duplicate('P', game, y, x);
			if (curr_line[x] == 'E')
				is_duplicate('E', game, y, x);
			if (curr_line[x] == 'C')
				game->c += 1;
		}
		if ((x == ft_strlen(curr_line) - 2) && (curr_line[x] != '1'))
			return (0);
		x++;
	}
	return (1);
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

static int	is_valid_size(t_list *lst) // necessary function?
{
	int	total_char;

	total_char = 0;
	while (lst->next)
	{
		total_char += (ft_strlen(lst->content) - 1);
		lst = lst->next;
	}
	total_char += (ft_strlen(lst->content) - 1);
	if (total_char < 15)
		return (0);
	return (1);
}

/* This function check the line format and call other functions which
check other validation requirements (n of items, kind of items etc.) */
static int	is_valid_line(t_state *game, t_list *lst)
{
	int	y;

	if (!(is_valid_first_last_line(lst->content)))
		return (0);
	lst = lst->next;
	y = 0;
	while (lst->next)
	{
		y++;
		if (!is_valid_mid_line(lst->content, game, y))
			return (0);
		lst = lst->next;
	}
	if (!(is_valid_first_last_line(lst->content)))
		return (0);
	return (1);
}

int	is_valid_format(t_list *lst, t_state *game)
{
	if (!is_valid_line(game, lst))
	{
		// ft_lstclear(&lst, lst_delnode); --- /???
		return (0);
	}
	if (!(game->p.x) || !(game->e) || !(game->c))
		return (0);
	if (!(is_rectangle(lst)))
		return (0);
	if (!(is_valid_size(lst)))
		return (0);
	return (1);
}





