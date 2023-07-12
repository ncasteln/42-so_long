/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:29:25 by ncasteln          #+#    #+#             */
/*   Updated: 2023/04/04 14:20:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_char_match(const char *s, char c, size_t i)
{
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!ft_strlen(s2))
		return ((char *) s1);
	i = 0;
	while (s1[i] && (get_char_match(s1, s2[0], i) + ft_strlen(s2) <= n))
	{
		i = get_char_match(s1, s2[0], i);
		k = 0;
		j = 0;
		while ((s2[j]) && (s2[j] == s1[i + k]))
		{
			j++;
			k++;
			if (j == ft_strlen(s2))
				return ((char *) s1 + i);
		}
		i++;
	}
	return (NULL);
}
