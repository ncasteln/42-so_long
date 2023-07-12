/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:18:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/11 11:08:50 by ncasteln         ###   ########.fr       */
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
			nc_exit("Too many P items in the map", __FILE__, __func__, __LINE__);
		game->p.y = y;
		game->p.x = x;
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
				nc_exit("Invalid item", __FILE__, __func__, __LINE__);
			if (curr_line[x] == 'P')
				is_duplicate('P', game, y, x);
			if (curr_line[x] == 'E')
				game->e += 1;
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

int	is_valid_line(t_list *lst, t_state *game)
{
	int		y;
	t_list	*node;

	node = lst;
	if (!(is_valid_first_last_line(node->content)))
		nc_exit("Invalid line", __FILE__, __func__, __LINE__);	// lstclear()
	node = node->next;
	y = 0;
	while (node->next)
	{
		y++;
		if (!is_valid_mid_line(node->content, game, y))
			nc_exit("Invalid line", __FILE__, __func__, __LINE__); //lstclear()
		node = node->next;
	}
	if (!(is_valid_first_last_line(node->content)))
		nc_exit("Invalid line", __FILE__, __func__, __LINE__); //lstclear()
	if (!(game->p.x) || !(game->e) || !(game->c))
		nc_exit("Some items left", __FILE__, __func__, __LINE__); //lstclear()
	if (!(is_rectangle(lst)))
		nc_exit("Map has too many angles", __FILE__, __func__, __LINE__); //lstclear()
	if (!(is_valid_size(lst)))
		nc_exit("Wrong map size (too little)", __FILE__, __func__, __LINE__); //lstclear()
	return (1);
}
