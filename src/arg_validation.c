/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:21 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/12 16:45:07 by ncasteln         ###   ########.fr       */
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
		nc_exit("Failed to open fd", __FILE__, __func__, __LINE__);
	lst = NULL;
	s = get_next_line(fd);
	while (s)
	{
		new_node = ft_lstnew(s);
		if (!new_node)
		{
			// free() ft_lstclear()
		}
		ft_lstadd_back(&lst, new_node);
		s = get_next_line(fd);
	}
	close(fd);
	if (!lst)
		nc_exit("Unable to create a list from file", __FILE__, __func__, __LINE__);
	return (lst);
}

static void	del(void *line)
{
	if (line)
		free(line);
}

void	validate(int argc, char **argv, t_state *game)
{
	t_list	*lst;

	if (!(argc == 2) || !(nc_is_valid_ext(argv[1], ".ber")))
		nc_exit("Invalid Arguments", __FILE__, __func__, __LINE__);

	// create a lst from lines
	lst = lines_to_lst(argv[1]);

	// various checks
	is_valid_line(lst, game);

	// cpy lst to dptr
	game->map = lst_to_dptr(lst, ft_lstsize(lst));
	ft_lstclear(&lst, del); // -------------------------------- del function ?
	if (!game->map)
		nc_exit("Unable to create map", __FILE__, __func__, __LINE__);// ------ --- ----// free()

	// path check
	is_valid_path(game);

}
