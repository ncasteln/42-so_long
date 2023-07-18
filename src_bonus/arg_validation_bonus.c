/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:21 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 14:22:56 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			return (ft_lstclear(&lst, lst_delnode), NULL);
		ft_lstadd_back(&lst, new_node);
		s = get_next_line(fd);
	}
	close(fd);
	if (!lst)
		return (ft_lstclear(&lst, lst_delnode), NULL);
	return (lst);
}

int	validate(int argc, char **argv, t_state *game)
{
	t_list	*lst;

	if (!(argc == 2) || !(nc_is_valid_ext(argv[1], ".ber")))
		return (0);
	lst = lines_to_lst(argv[1]);
	if (!lst)
		return (0);
	if (!is_valid_format(lst, game))
		return (ft_lstclear(&lst, lst_delnode), 0);
	game->map = lst_to_dptr(lst, ft_lstsize(lst));
	ft_lstclear(&lst, lst_delnode);
	if (!game->map)
		return (0);
	if (!is_valid_path(game))
		return (0);
	return (1);
}
