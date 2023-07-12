/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:04 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/04 10:30:52 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*allocate(int start, int end)
{
	char	*p;

	if (end == 0)
		p = malloc (1 * sizeof(char));
	else
		p = malloc((end - start + 1) * sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

static int	is_match(char c, const char *set)
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(set))
	{
		if (c == *(set + j))
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*p;
	int		start;
	int		end;
	int		i;

	p = NULL;
	start = 0;
	end = ft_strlen(str) - 1;
	while (is_match(*(str + start), set) == 1)
		start++;
	while (is_match(*(str + end), set) == 1)
		end--;
	end++;
	p = allocate(start, end);
	if (!p)
		return (NULL);
	i = 0;
	while (start < end)
	{
		*(p + i) = *(str + start);
		start++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
