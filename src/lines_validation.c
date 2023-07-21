/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:18:08 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:49:31 by ncasteln         ###   ########.fr       */
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

static void	is_valid_mid_line(const char *line, t_data *data, int y)
{
	size_t		x;

	x = 0;
	while (line[x])
	{
		if ((x == 0) && (line[x] != '1'))
			return (free_data(data), err_print(INV_FORMAT));
		if ((x > 0 && x < ft_strlen(line) - 2))
		{
			if (!is_valid_item(line[x]))
				return (free_data(data), err_print(INV_ITEM));
			if (line[x] == 'P' && is_double_item('P', data, y, x))
				return (free_data(data), err_print(DOUB_ITEM));
			if (line[x] == 'E' && is_double_item('E', data, y, x))
				return (free_data(data), err_print(DOUB_ITEM));
			if (line[x] == 'C')
				data->c += 1;
		}
		if ((x == ft_strlen(line) - 2) && (line[x] != '1'))
			return (free_data(data), err_print(INV_FORMAT));
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
static void	is_valid_line(t_data *data)
{
	int		y;
	t_list	*temp;

	temp = data->lines;
	if (!(is_valid_first_last_line(temp->content)))
		return (free_data(data), err_print(INV_FORMAT));
	y = 1;
	temp = temp->next;
	while (temp->next)
	{
		is_valid_mid_line(temp->content, data, y);
		temp = temp->next;
		y++;
	}
	if (!(is_valid_first_last_line(temp->content)))
		return (free_data(data), err_print(INV_FORMAT));
}

void	is_valid_format(t_data *data)
{
	is_valid_line(data);
	if (!(data->p.x) || !(data->e) || !(data->c))
		return (free_data(data), err_print(MISS_ITEM));
	if (!is_rectangle(data->lines))
		return (free_data(data), err_print(INV_MAPSHAPE));
}
