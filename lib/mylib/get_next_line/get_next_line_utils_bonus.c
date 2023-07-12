/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:48:51 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/15 12:04:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen_mod(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_mod(char *str, int c)
{
	char	*p;
	int		i;

	if (!str)
		return (NULL);
	p = (char *) str;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char) c)
			return (p + i);
		i++;
	}
	return (NULL);
}

static void	*ft_memcpy_mod(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dest) && (!src))
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_substr_mod(char *s, unsigned int start, size_t n)
{
	char	*p;
	size_t	i;

	p = malloc ((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while ((i < n) && s[start])
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_mod(char *line, char *buff)
{
	int		line_len;
	int		buff_len;
	char	*new_line;

	line_len = ft_strlen_mod(line);
	buff_len = ft_strlen_mod(buff);
	new_line = malloc ((line_len + buff_len + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	ft_memcpy_mod(new_line, line, line_len);
	ft_memcpy_mod(new_line + line_len, buff, buff_len);
	new_line[line_len + buff_len] = '\0';
	free(line);
	return (new_line);
}
