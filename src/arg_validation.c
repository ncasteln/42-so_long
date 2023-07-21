/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:21 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/21 11:59:05 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*lines_to_lst(const char *path)
{
	int		fd;
	char	*s;
	t_list	*lst;
	t_list	*new_node;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = NULL;
	s = get_next_line(fd);
	while (s)
	{
		new_node = ft_lstnew(s);
		if (!new_node)
			return (ft_lstclear(&lst, del_line), NULL);
		ft_lstadd_back(&lst, new_node);
		s = get_next_line(fd);
	}
	close(fd);
	if (!lst)
		return (ft_lstclear(&lst, del_line), NULL);
	return (lst);
}

void	validate(int argc, char **argv, t_data *data)
{
	if (!(argc == 2) || !(nc_is_valid_ext(argv[1], ".ber")))
		return (free_data(data), err_print(INV_ARG));
	data->lines = lines_to_lst(argv[1]);
	if (!data->lines)
		return (free_data(data), err_print(READ_LST_FAIL));
	is_valid_format(data);
	data->map = lst_to_dptr(data->lines, ft_lstsize(data->lines));
	ft_lstclear(&data->lines, del_line);
	if (!data->map)
		return (free_data(data), err_print(MAP_FAIL));
	is_valid_path(data);
}
