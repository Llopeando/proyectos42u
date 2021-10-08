/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:54 by ullorent          #+#    #+#             */
/*   Updated: 2021/10/08 12:41:36 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		c;

	c = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
	{
		mem = (char *)malloc(ft_strlen(s + start) + 1);
		len = ft_strlen(s + start);
	}
	else if (start < ft_strlen(s))
		mem = malloc(len + 1);
	else
		mem = (char *)malloc(1);
	if (!mem || !s)
		return (NULL);
	while (len > 0 && start < ft_strlen(s))
	{
		mem[c - start] = s[c];
		c++;
		len--;
	}
	mem[c - start] = '\0';
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c;
	size_t	i;
	char	*mem;

	c = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	while (s1[c] != '\0')
	{
		*mem = s1[c];
		c++;
		mem++;
	}
	while (s2[i] != '\0')
	{
		*mem = s2[i];
		i++;
		mem++;
	}
	*mem = '\0';
	return (mem - c - i);
}
